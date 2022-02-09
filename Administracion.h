struct Recepcionista{
	int IDrecep,Dni,permisoR;
	char apeynom[60],Telefono[60];
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
	char apeynom[60], Domicilio[60],Localidad[60],Telefono[25];
	int Dni;
	float peso;
	fecha fechadeNacimiento;
};
struct Turnos{
	int IDprof,DNIcliente;
	fecha FechaATENCION;
	char DetalleAtencion[60];
	
};
void CargarRecepcionista(FILE *recep,Recepcionista Recep)
{
	recep = fopen ("Recepcionistas.dat ","a+b");
	printf("Ingrese el apellido y nombre: ");
    _flushall();
    gets(Recep.apeynom);
    printf("Ingrese el DNI: ");
    scanf("%d",&Recep.Dni);
    printf("Ingrese el telefono: ");
    _flushall();
    gets(Recep.Telefono); 
	  
	int permisos,n,min=0,may=0,dig=0;
	char contra[60];
			printf("\nEL USUARIO DEBE: \n1. Comenzar con una letra minuscula.\n2. Tener al menos 2 letras mayusculas.\n3. Tener como maximo 3 digitos.\n");
			do{	
			printf ("\nNombre de usuario: ");
			_flushall();
			gets(Recep.UsuarioR);
			n=strlen(Recep.UsuarioR);
			//Primera letra en minuscula
			if (Recep.UsuarioR[0] <= 122 && Recep.UsuarioR[0]>= 97) min++;
			//Tener dos letras mayusculas
			for (int i=0;i<n;i++)
			{
			if (Recep.UsuarioR[i] <= 90 && Recep.UsuarioR[i]>= 65) may++;
			}
			//tener maximo 3 digitos
			for (int i=0;i<n;i++)
			{
		        if ( (Recep.UsuarioR[i] >= 33) && (Recep.UsuarioR[i]<= 47) || (Recep.UsuarioR[i] >= 58) && (Recep.UsuarioR[i]<= 64)|| (Recep.UsuarioR[i] >= 166) && (Recep.UsuarioR[i]<= 175)) dig++;
		    }
		    if(n<6 or n>10 or min==0 or may<2 or dig>3)
				{
					printf("\nEL USUARIO DEBE: \n1. Comenzar con una letra minuscula.\n2. Tener al menos 2 letras mayusculas.\n3. Tener como maximo 3 digitos.\n");
				}
			//CORRECTO 
			if(n>=6 and n<=10 and min==1 and may>=2)
			{
	
				printf("CORRECTO!");
			}
		}while(n<6 or n>10 or min==0 or may<2 or dig>3);

			printf ("\nContrasenia: ");
			_flushall();
			gets(contra);
			printf("Permisos: \n Administrador 1 \nRecepcionista 2\Profecional medico 3: ");
			scanf("%d",&Recep.permisoR);;
	    fwrite(&Recep,sizeof(Recepcionista),1,recep);
		fclose(recep);
}
void CargarProfesional(FILE *prof,Profesionales Prof)
{
	Profesionales user_aux;
	int b=0;
	int permisos,n,min=0,may=0,dig=0,bandera=0,espacio=0,conse=0,cons=0;
	char contra[60];
	
	//Validacion de usuario
	printf("\nEL USUARIO DEBE: \n1. Comenzar con una letra minuscula.\n2. Tener al menos 2 letras mayusculas.\n3. Tener como maximo 3 digitos.\n");
	
	printf ("\nNombre de usuario: ");
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
		printf("\nEl Usuario ingresado ya existe, por favor ingrese otro");
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
					printf("\nUsuario valido");
					bandera=1;
				}
				else
				{
					printf("\nEl usuario no puede tener mas de 3 digitos");
					printf("\nUsuario invalido");
				}
			}
		else
		{
			printf("\nNo posee la cantidad minima de mayusculas deben ser al menos 2");
			printf("\nUsuario invalido");
		}
		}
		else
		{
			printf("\nLa primera letra del usuario debe ser minuscula.");
			printf("\nUsuario invalido");
		}
	}
		else
		{
			printf("\nLa cantidad de caracteres debe ser de 6 a 10");
			printf("\nUsuario invalido\n");
		}
	
	if(bandera==1)
	{
		printf("\nIngrese la contrasenia: ");
		_flushall();
		gets(Prof.ContraseniaP);
		if(strlen(Prof.ContraseniaP)>=6 and strlen(Prof.ContraseniaP)<=32)
		{
			for(int i=0;i<=Prof.ContraseniaP[i];i++)
			{
				if(Prof.ContraseniaP[i]>=40 and Prof.ContraseniaP[i]<=47 or Prof.ContraseniaP[i]>=58 and Prof.ContraseniaP[i]<=63 or Prof.ContraseniaP[i]>=90 and Prof.ContraseniaP[i]<=96 or Prof.ContraseniaP[i]>=123 and Prof.ContraseniaP[i]<=126 or Prof.ContraseniaP[i]==239)
				{
					printf("\nLa contrasenia no puede contener signos de puntuacion o acentos");
				}
				else if(Prof.ContraseniaP[i]==' ')
				{
					espacio=espacio+1;
					printf("\nLa contrasenia no debe tener espacios");
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
						printf("\nContrasenia valida");
						bandera=2;
					}
					else
					{
						printf("\nLa contrasenia no puede tener dos letras seguidas");
					}
				}
				else
				printf("\nLa contrasenia no debe tener mas de 4 numeros consecutivos");
			}
		}
		else
		{
			printf("\nLa Contrasenia debe tener entre 6 y 32 caracteres");
		}
	}

	if(bandera==2)
	{
		printf("Ingrese nombre y apellido: ");
	   	_flushall();
	    gets(Prof.apeynom);
	    printf("Ingrese el DNI: ");
	    scanf("%d", &Prof.Dni);
	    printf("Ingrese el telefono: ");
	    _flushall();
	    gets(Prof.Tel);
		fwrite(&Prof,sizeof(Profesionales),1,prof);
	}

	fclose(prof);
	
}

void ver(FILE *prof,Profesionales Prof)
{
	printf("VER");
	prof = fopen ("Profesionales.dat","a+b");
	fread(&Prof,sizeof(Profesionales),1,prof);

		while(!feof(prof))
		{
		printf("\nNombre y apellido: %s", Prof.apeynom);
		printf("\nDNI: %d", Prof.Dni);
		printf("\nTelefono: %s", Prof.Tel);
		printf("\nUsuario: %s",Prof.UsuarioP);
		printf("\nContrasenia: %s",Prof.ContraseniaP);
		fread(&Prof,sizeof(Profesionales),1,prof);
		}

	fclose(prof);
}
