struct Recepcionista{
	int IDrecep,Dni,permisoR;
	char apeynom[60],Tel[60];
	char UsuarioR[60],ContraseniaR[50];
}Recep;
struct Profesionales{
	int IDprof,Dni,permisoP;
	char apeynom[60];
	char Tel[25];
	char UsuarioP[60],ContraseniaP[50];
}Prof;
struct fecha{
	int dia,mes,anio;
};
struct Cliente{
	char apeynom[60], Domicilio[60],Localidad[60],Telefono[25],Dni[50];
	float peso;
	fecha fechadeNacimiento;
}Clien;
struct Turnos{
	int IDprof;
	fecha FechaATENCION;
	char DetalleAtencion[60],apeynom[50],DNIcliente[50];
}Turn;
struct Atenciones{
	int IDprof;
	int cant_atenciones;
}Aten;
void CargarRecepcionista(FILE *recep,Recepcionista Recep)
{	
	Recepcionista user_aux;
	int b=0;
	int permisos,n,min=0,may=0,dig=0,bandera=0,espacio=0,conse=0,cons=0;
	char contra[60];
	//Validacion de usuario
	do{
	system("color 74");
	marco();
	gotoxy(48,4);
	printf("EL USUARIO DEBE TENER:");
	gotoxy(48,5);
	printf("1. Comenzar con una letra minuscula.");
	gotoxy(48,6);
	printf("2. Tener al menos 2 letras mayusculas.");
	gotoxy(48,7);
	printf("3. Tener como maximo 3 digitos.");
	gotoxy(48,10);
	printf ("Nombre de usuario: ");
	_flushall();
	gets(Recep.UsuarioR);
	//validar que no exista el mismo usuario
	recep=fopen("Recepcionistas.dat","rb");
	
	if(recep!=NULL)
	{
		fread(&user_aux,sizeof(Recepcionista),1,recep);
		while(!feof(recep))
		{
			if(strcmp(Recep.UsuarioR,user_aux.UsuarioR)==0)
			{
				b=1;
			}
			fread(&user_aux,sizeof(Recepcionista),1,recep);
		}
	}
	fclose(recep);
	
	if(b==1)
	{
		gotoxy(48,11);
		printf("El Usuario ingresado ya existe, por favor ingrese otro");
	}
	
	//Entre 6 y 10 caracteres 	
	recep=fopen("Recepcionistas.dat","ab");
	if(strlen(Recep.UsuarioR)>=6 and strlen(Recep.UsuarioR)<=10 and b!=1)
	{
		//Primera letra en minuscula
		if (Recep.UsuarioR[0] <= 122 && Recep.UsuarioR[0]>= 97)
		{
			min++;

		//Tener dos letras mayusculas
		for (int i=0;i<Recep.UsuarioR[i];i++)
		{
			if (Recep.UsuarioR[i] <= 90 && Recep.UsuarioR[i]>= 65)
			{
				may++;
			}
			if (Recep.UsuarioR[i] >= 48 && Recep.UsuarioR[i]<= 57)
			{
				 dig++;
			}
		}
		if(may>=2)
			{
				if(dig<=3)
				{
					gotoxy(48,12);
					printf("Usuario valido");
					gotoxy(48,14);
					system("pause");
					bandera=1;
				}
				else
				{
					gotoxy(48,12);
					printf("El usuario no puede tener mas de 3 digitos");
					gotoxy(48,13);
					printf("Usuario invalido");
					gotoxy(48,15);
					system("pause");
				}
			}
		else
		{
			gotoxy(48,12);
			printf("No posee la cantidad minima de mayusculas deben ser al menos 2");
			gotoxy(48,13);
			printf("Usuario invalido");
			gotoxy(48,15);
			system("pause");
		}
		}
		else
		{
			gotoxy(48,12);
			printf("La primera letra del usuario debe ser minuscula.");
			gotoxy(48,13);
			printf("Usuario invalido");
			gotoxy(48,15);
			system("pause");
		}
	}
		else
		{
			gotoxy(48,12);
			printf("La cantidad de caracteres debe ser de 6 a 10");
			gotoxy(48,13);
			printf("Usuario invalido");
			gotoxy(48,15);
			system("pause");
		}
		system("cls");
	}while(bandera!=1);
	//contraseña
	do{
		system("color 74");
		marco();
	if(bandera==1){
		gotoxy(45,4);
		printf("LA CONTRASEÑA DEBE TENER: ");
		gotoxy(45,5);
		printf("1. Al menos una letra mayuscula, una letra minuscula y un numero.");
		gotoxy(45,6);
		printf("2.Solo caracteres alfanumericos.");
		gotoxy(45,7);
		printf("3. Debera tener entre 6 y 32 caracteres.");
		gotoxy(45,8);
		printf("4. No debe tener más de 3 caracteres numericos consecutivos.");
		gotoxy(45,9);
		printf("5. No debe tener 2 letras alfabéticamente consecutivas.");
		gotoxy(45,11);
		printf("Ingrese la contrasenia: ");
		_flushall();
		gets(Recep.ContraseniaR);
		if(strlen(Recep.ContraseniaR)>=6 and strlen(Recep.ContraseniaR)<=32)
		{
			for(int i=0;i<=Recep.ContraseniaR[i];i++)
			{
				if(Recep.ContraseniaR[i]>=40 and Recep.ContraseniaR[i]<=47 or Recep.ContraseniaR[i]>=58 and Recep.ContraseniaR[i]<=63 or Recep.ContraseniaR[i]>=90 and Recep.ContraseniaR[i]<=96 or Recep.ContraseniaR[i]>=123 and Recep.ContraseniaR[i]<=126 or Recep.ContraseniaR[i]==239)
				{
					gotoxy(48,13);
					printf("La contrasenia no puede contener signos de puntuacion o acentos");
					gotoxy(45,15);
					system("pause");
				}
				else if(Recep.ContraseniaR[i]==' ')
				{
					espacio=espacio+1;
					gotoxy(48,13);
					printf("La contrasenia no debe tener espacios");
					gotoxy(45,15);
					system("pause");
				}
				
				if(Recep.ContraseniaR[i]>=48 and Recep.ContraseniaR[i]<=57)
				{
					if(Recep.ContraseniaR[i]+1==Recep.ContraseniaR[i+1])
					{
						conse=conse+1;//numeros consecutivos
					}
					
				}
				if((Recep.ContraseniaR[i]>=65 and Recep.ContraseniaR[i]<=90) or (Recep.ContraseniaR[i]>=97 and Recep.ContraseniaR[i]<=122))
				{
					if(Recep.ContraseniaR[i]+1==Recep.ContraseniaR[i+1])
					{
						cons=cons+1;//Letras seguidas
					}
				}
		
			}

			if(espacio==0)
			{
				if(conse<3)
				{
					if(cons<1)
					{
						gotoxy(45,13);
						printf("Contrasenia valida");
						gotoxy(45,15);
						system("pause");
						bandera=2;
					}
					else
					{
						gotoxy(48,13);
						printf("La contrasenia no puede tener dos letras seguidas");
						gotoxy(45,15);
						system("pause");
					}
				}
				else
				{
				gotoxy(48,13);
				printf("La contrasenia no debe tener mas de 4 numeros consecutivos");
				gotoxy(45,15);
				system("pause");
				}
			}
		}
		else
		{
	
			gotoxy(48,13);
			printf("La Contrasenia debe tener entre 6 y 32 caracteres");
			gotoxy(45,15);
			system("pause");
		}
	}
	system("cls");
	}while(bandera!=2);
	//ingreso datos del usuario
	if(bandera==2){
		gotoxy(44,3);
		printf("USUARIO: %s",Recep.UsuarioR);
		srand(time(NULL));
		Recep.IDrecep = 1+rand()%201;//le damos un id aleatorio
		gotoxy(44,5);
		printf("Ingrese nombre y apellido: ");
	   	_flushall();
	    gets(Recep.apeynom);
	    gotoxy(44,6);
	    printf("Ingrese el DNI: ");
	    scanf("%d", &Recep.Dni);
	    gotoxy(44,7);
	    printf("Ingrese el telefono: ");
	    _flushall();
	    gets(Recep.Tel);
	    gotoxy(44,8);
	    printf("Permisos: admin=1,Recepcionista=2,Profecional=3");
	    scanf("%d",&Recep.permisoR);
		fwrite(&Recep,sizeof(Recepcionista),1,recep);
	}
	fclose(recep);
}
void CargarProfesional(FILE *prof,Profesionales Prof)
{
	Profesionales user_aux;
	int b=0;
	int permisos,n,min=0,may=0,dig=0,bandera=0,espacio=0,conse=0,cons=0;
	char contra[60];
	
	//Validacion de usuario
	do{
	system("color 74");
	marco();
	gotoxy(48,4);
	printf("EL USUARIO DEBE TENER:");
	gotoxy(48,5);
	printf("1. Comenzar con una letra minuscula.");
	gotoxy(48,6);
	printf("2. Tener al menos 2 letras mayusculas.");
	gotoxy(48,7);
	printf("3. Tener como maximo 3 digitos.");
	gotoxy(48,10);
	printf ("Nombre de usuario: ");
	_flushall();
	gets(Prof.UsuarioP);
	//validar que no exista el mismo usuario
	
	prof=fopen("Profesionales.dat","rb");
	
	if(prof!=NULL)
	{
		fread(&user_aux,sizeof(Profesionales),1,prof);
		while(!feof(prof))
		{
			if(strcmp(Prof.UsuarioP,user_aux.UsuarioP)==0)
			{
				b=1;
			}
			fread(&user_aux,sizeof(Profesionales),1,prof);
		}
	}
	fclose(prof);
	
	if(b==1)
	{
		gotoxy(48,11);
		printf("El Usuario ingresado ya existe, por favor ingrese otro");

	}
	//Entre 6 y 10 caracteres 	
	prof=fopen("Profesionales.dat","ab");
	if(strlen(Prof.UsuarioP)>=6 and strlen(Prof.UsuarioP)<=10 and b!=1)
	{
		//Primera letra en minuscula
		if (Prof.UsuarioP[0] <= 122 && Prof.UsuarioP[0]>= 97)
		{
			min++;

		//Tener dos letras mayusculas
		for (int i=0;i<Prof.UsuarioP[i];i++)
		{
			if (Prof.UsuarioP[i] <= 90 && Prof.UsuarioP[i]>= 65)
			{
				may++;
			}
			if (Prof.UsuarioP[i] >= 48 && Prof.UsuarioP[i]<= 57)
			{
				 dig++;
			}
		}
		if(may>=2)
			{
				if(dig<=3)
				{
					gotoxy(48,12);
					printf("Usuario valido");
					gotoxy(48,14);
					system("pause");
					bandera=1;
				}
				else
				{
					gotoxy(48,12);
					printf("El usuario no puede tener mas de 3 digitos");
					gotoxy(48,14);
					printf("Usuario invalido");
					gotoxy(48,16);
					system("pause");
				}
			}
		else
		{
			gotoxy(48,12);
			printf("No posee la cantidad minima de mayusculas deben ser al menos 2");
			gotoxy(48,14);
			printf("Usuario invalido\n");
			gotoxy(48,16);
			system("pause");
		}
		}
		else
		{
			gotoxy(48,12);
			printf("La primera letra del usuario debe ser minuscula.");
			gotoxy(48,14);
			printf("Usuario invalido\n");
			gotoxy(48,16);
			system("pause");
		}
	}
		else
		{
			gotoxy(48,12);
			printf("La cantidad de caracteres debe ser de 6 a 10");
			gotoxy(48,14);
			printf("Usuario invalido\n");
			gotoxy(48,16);
			system("pause");
		}
	system("cls");
	}while(bandera!=1);
	//CONTRASEÑA	
	do{
	system("color 74");
	marco();
	if(bandera==1)
	{
	gotoxy(45,4);
	printf("LA CONTRASEÑA DEBE TENER: ");
	gotoxy(45,5);
	printf("1. Al menos una letra mayuscula, una letra minuscula y un numero.");
	gotoxy(45,6);
	printf("2.Solo caracteres alfanumericos.");
	gotoxy(45,7);
	printf("3. Debera tener entre 6 y 32 caracteres.");
	gotoxy(45,8);
	printf("4. No debe tener más de 3 caracteres numericos consecutivos.");
	gotoxy(45,9);
	printf("5. No debe tener 2 letras alfabéticamente consecutivas.");
	gotoxy(45,11);
	printf("Ingrese la contrasenia: ");
	_flushall();
	gets(Prof.ContraseniaP);
		if(strlen(Prof.ContraseniaP)>=6 and strlen(Prof.ContraseniaP)<=32)
		{
			for(int i=0;i<=Prof.ContraseniaP[i];i++)
			{
				if(Prof.ContraseniaP[i]>=40 and Prof.ContraseniaP[i]<=47 or Prof.ContraseniaP[i]>=58 and Prof.ContraseniaP[i]<=63 or Prof.ContraseniaP[i]>=90 and Prof.ContraseniaP[i]<=96 or Prof.ContraseniaP[i]>=123 and Prof.ContraseniaP[i]<=126 or Prof.ContraseniaP[i]==239)
				{
					gotoxy(45,13);
					printf("La contrasenia no puede contener signos de puntuacion o acentos");
					gotoxy(45,15);
					system("pause");
				}
				else if(Prof.ContraseniaP[i]==' ')
				{
					espacio=espacio+1;
					gotoxy(45,13);
					printf("La contrasenia no debe tener espacios");
					gotoxy(45,15);
					system("pause");
				}
				
				if(Prof.ContraseniaP[i]>=48 and Prof.ContraseniaP[i]<=57)
				{
					if(Prof.ContraseniaP[i]+1==Prof.ContraseniaP[i+1])
					{
						conse=conse+1;//numeros consecutivos
					}
					
				}
				if((Prof.ContraseniaP[i]>=65 and Prof.ContraseniaP[i]<=90) or (Prof.ContraseniaP[i]>=97 and Prof.ContraseniaP[i]<=122))
				{
					if(Prof.ContraseniaP[i]+1==Prof.ContraseniaP[i+1])
					{
						cons=cons+1;//Letras seguidas
					}
				}
		
			}

			if(espacio==0)
			{
				if(conse<3)
				{
					if(cons<1)
					{
						gotoxy(45,13);
						printf("Contrasenia valida");
						gotoxy(45,15);
						system("pause");
						bandera=2;
					}
					else
					{
						gotoxy(45,13);
						printf("La contrasenia no puede tener dos letras seguidas");
						gotoxy(45,15);
						system("pause");
					}
				}
				else
				{
					if(conse>=4)
					{				
					gotoxy(45,14);
					printf("La contrasenia no debe tener mas de 4 numeros consecutivos");
					gotoxy(45,16);
					system("pause");
					}
				}
			}
		}
		else
		{
			gotoxy(45,13);
			printf("La Contrasenia debe tener entre 6 y 32 caracteres");
			gotoxy(45,15);
			system("pause");
		}
	}
	system("cls");
	}while(bandera!=2);
 	//ingreso datos del usuario
	if(bandera==2)
	{
	system("color 74");
	marco();
	gotoxy(44,3);
	printf("USUARIO: %s",Prof.UsuarioP);
	srand(time(NULL));
	Prof.IDprof = 1+rand()%201;//le damos un id aleatorio , faltaria validacion de que no existe previamente.
	gotoxy(44,5);
	printf("Ingrese nombre y apellido: ");
	_flushall();
	gets(Prof.apeynom);
	gotoxy(44,6);
    printf("Ingrese el DNI: ");
	scanf("%d", &Prof.Dni);
	gotoxy(44,7);
	printf("Ingrese el telefono: ");
	_flushall();
	gets(Prof.Tel);
	gotoxy(44,8);
	printf("Permisos: admin=1,Recepcionista=2,Profecional=3");
	scanf("%d",&Prof.permisoP);
	fwrite(&Prof,sizeof(Profesionales),1,prof);
	}

	fclose(prof);
	
}
void atenciones(FILE *turn, Turnos Turn) //errores
{
	system("color 74");
	marco();
	
	int mes,b=0;
	turn=fopen("Turnos.dat","rb");
	
	gotoxy(40,3);
	printf("Ingrese el mes para mostrar las atenciones: ");
	scanf("%d",&mes);
	
	fread(&Turn,sizeof(Turnos),1,turn);
	while(!feof(turn))
	{
		marco();
		if(mes==Turn.FechaATENCION.mes)
		{
			b=1;
			gotoxy(40,4);
			printf("Fecha:");
			gotoxy(47,4);
			printf("%d/",Turn.FechaATENCION.dia);
			gotoxy(51,4);
			printf("%d/",Turn.FechaATENCION.mes);
			gotoxy(55,4);
			printf("%d",Turn.FechaATENCION.anio);
			gotoxy(40,5);
			printf("DNI del paciente: %s",Turn.DNIcliente);
			gotoxy(40,7);
			printf("Detalles de atencion: %s\n",Turn.DetalleAtencion);
			gotoxy(46,10);
			system("pause");
			system("cls");
			gotoxy(46,4);
		}
		fread(&Turn,sizeof(Turnos),1,turn);
	}
	fclose(turn);
	if(b==0)
	{
		gotoxy(46,4);
		printf("No hay turnos para el mes ingresado");
		gotoxy(46,6);
		system("pause");
	}

														 
}
void ranking(Profesionales Prof,Turnos Turn,Atenciones Aten)
{
	system("color 74");
	marco();
	
	FILE *arch;
	Profesionales reg_med[50];
	Turnos reg_turnos[50];
	Atenciones reg_atenciones[50],aux;

	bool band = true,stop;
    int i = 0,num_meds = 0,num_turnos = 0,contador = 0;

    //Archivo de Medicos:
    arch=fopen("Profesionales.dat","rb");

    if (arch==NULL)
    {
    system("color 74");
	marco();
    	gotoxy(30,5);
        printf("El archivo 'Profesionales.dat' no fue creado o se elimino, contacte con soporte.");
		band = false;
		gotoxy(30,8);
		system("pause");
    }
    else
    {
        fread(&reg_med[i],sizeof(Profesionales),1,arch);
        while (!feof(arch))
        {
            i++;
            fread(&reg_med[i],sizeof(Profesionales),1,arch);
        }
        num_meds = i;
        i = 0;
        fclose(arch);
    }

	//Archivo de turnos:
    arch=fopen("Turnos.dat","rb");

    if (arch==NULL)
    {
    system("color 74");
	marco();
    	gotoxy(30,6);
        printf("El archivo 'Turnos.dat' no fue creado o se elimino, contacte con soporte.");
		band = false;
		gotoxy(30,8);
		system("pause");
		
    }
    else
    {
        fread(&reg_turnos[i],sizeof(Turnos),1,arch);
        while (!feof(arch))
        {
            i++;
            fread(&reg_turnos[i],sizeof(Turnos),1,arch); 
        }
        num_turnos = i;
        i = 0;
        fclose(arch);
    }

	if (band)
	{
		//Obtiene la cantidad de turnos por Medico:
		for (i = 0; i < num_meds; i++)
		{
			contador = 0;

			for (int k = 0; k < num_turnos; k++)
			{
				if ((reg_med[i].IDprof == reg_turnos[k].IDprof) /*and (reg_turnos[k].mostrado == 1)*/)
				{
					contador++;
				}
			}
			
			reg_atenciones[i].IDprof = reg_med[i].IDprof;
			reg_atenciones[i].cant_atenciones = contador;
		}
		
		//Ordena el ranking de mayor a menor:
		do
		{
			stop=false;
			
			for (i = 0 ; i < num_meds-1 ; i++)
			{
				if(reg_atenciones[i].cant_atenciones < reg_atenciones[i+1].cant_atenciones)
				{
					aux=reg_atenciones[i];
					reg_atenciones[i]=reg_atenciones[i+1];
					reg_atenciones[i+1]=aux;
					stop=true;
				}
			}
		}
		while (stop);

		//Muestra el ranking de Medicos:
		for (i = 0; i < num_meds; i++)
		{
			gotoxy(46,4);
			printf("Puesto %d:",i+1);
			gotoxy(46,5);
			printf("ID: %d",reg_atenciones[i].IDprof);
			gotoxy(46,6);
			printf("Nombre y apellido: %s",reg_med[i].apeynom);
			gotoxy(46,7);
			printf("Cantidad de atenciones: %d",reg_atenciones[i].cant_atenciones);
			gotoxy(46,8);
			system("pause");
			system("cls");
			gotoxy(46,4);			
		}
		
	}
	
}
void ver(FILE *prof,Profesionales Prof,FILE *recep, Recepcionista Recep)
{
	gotoxy(48,3);
	printf("Profesionales");
	prof = fopen ("Profesionales.dat","a+b");
	fread(&Prof,sizeof(Profesionales),1,prof);
	
	while(!feof(prof))
	{
	system("color 74");
	marco();
		gotoxy(48,5);
		printf("ID profesional: %d",Prof.IDprof);
		gotoxy(48,6);
		printf("Nombre y apellido: %s", Prof.apeynom);
		gotoxy(48,7);
		printf("DNI: %d", Prof.Dni);
		gotoxy(48,8);
		printf("Telefono: %s", Prof.Tel);
		gotoxy(48,9);
		printf("Usuario: %s",Prof.UsuarioP);
		gotoxy(48,10);
		printf("Contrasenia: %s",Prof.ContraseniaP);
		gotoxy(48,11);
		printf("Permiso: ");
		if(Prof.permisoP==1)
		{
			printf("Administracion");
		}
		else
		{
			if(Prof.permisoP==2)
			{
				printf("Recepcionista");
			}
			else
			{
				if(Prof.permisoP==3)
				{
					printf("Espacios");
				}
			}
		}
		fread(&Prof,sizeof(Profesionales),1,prof);
		gotoxy(48,13);
		system("pause");
		system("cls");
		gotoxy(48,3);
		}
	fclose(prof);
	
	gotoxy(48,3);
	printf("Recepcionistas");
	recep = fopen ("Recepcionistas.dat","a+b");
	fread(&Recep,sizeof(Recepcionista),1,recep);

	while(!feof(recep))
	{
	system("color 74");
	marco();
		gotoxy(48,5);
		printf("ID: %d",Recep.IDrecep);
		gotoxy(48,6);
		printf("Nombre y apellido: %s",Recep.apeynom);
		gotoxy(48,7);
		printf("DNI: %d", Recep.Dni);
		gotoxy(48,8);
		printf("Telefono: %s", Recep.Tel);	
		gotoxy(48,9);
		printf("Usuario: %s",Recep.UsuarioR);
		gotoxy(48,10);
		printf("Contrasenia: %s",Recep.ContraseniaR);
		gotoxy(48,11);
		printf("Permiso: ");
		if(Recep.permisoR==1)
		{
			printf("Administracion");
		}
		else
		{
			if(Recep.permisoR==2)
			{
				printf("Recepcionista");
			}
			else
			{
				if(Recep.permisoR==3)
				{
					printf("Espacios");
				}
			}
		}
		fread(&Recep,sizeof(Recepcionista),1,recep);
		gotoxy(48,13);
		system("pause");
		system("cls");
		gotoxy(48,3);
		}
	fclose(recep);
}
