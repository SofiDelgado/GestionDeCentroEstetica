void Regcliente(FILE *client,Cliente Clien){
	system("color 75");
	marco();
	FILE *arch;
	int b=0;
	char Dni[50];
	client = fopen ("Clientes.dat","a+b");
	gotoxy(48,3);
	printf("=====================");
	gotoxy(48,4);
	printf("REGISTRAR CLIENTE");
	gotoxy(48,5);
	printf("=====================");
	gotoxy(48,7);
	printf("Ingrese el DNI del Cliente: ");
	_flushall();
	gets(Dni);
	
	/*arch=fopen("Clientes.dat","rb");
	fread(&Clien,sizeof(Cliente),1,arch);
    while (!feof(arch))
    {
		if(strcmp(Dni,Clien.Dni)==0)
		{
			b=1;
		break;
		}
		else
		{
			fread(&Clien,sizeof(Cliente),1,arch);
		}
    }
    fclose(arch);*/
    
    strcpy(Clien.Dni,Dni);	
    gotoxy(48,8);
	printf("Ingrese el nombre del Cliente: ");
	_flushall();
	gets(Clien.apeynom);
	gotoxy(48,9);
	printf("Ingrese el domicilio del Cliente: ");
	gets(Clien.Domicilio);
	gotoxy(48,10);	
	printf("Ingrese la localidad del Cliente: ");
	_flushall();
	gets(Clien.Localidad);
	gotoxy(48,11);
	printf("Ingrese la fecha de nacimiento del Cliente.");
	gotoxy(48,12);
	printf("Ingrese el dia: ");
	scanf("%d",&Clien.fechadeNacimiento.dia);
	gotoxy(48,13);
	printf("Ingrese el mes: ");
	scanf("%d",&Clien.fechadeNacimiento.mes);
	gotoxy(48,14);
	printf("Ingrese el anio: ");
	scanf("%d",&Clien.fechadeNacimiento.anio);
	gotoxy(48,15);
	printf("Ingrese el peso del Cliente (kg): ");
	scanf("%f",&Clien.peso); 
	gotoxy(48,16);
	printf("Ingrese el telefono del Cliente: ");
	_flushall();
	gets(Clien.Telefono);
	fwrite(&Clien,sizeof(Cliente),1,client);
	
	/*if(b==0)
	{
		gotoxy(48,8);
		printf("El cliente ya existe en nuestra base de datos");
		gotoxy(48,9);
		system("pause");
	}*/
	fclose(client);		
}

void Regturno (FILE *turn, Turnos Turn, FILE *prof, Profesionales Prof)
{
	FILE *arch;
	FILE *client;
	int a,aux;
	int b=0,c=0,buscar;
	char dnicliente[50];
	system("color 75");
	marco();
	gotoxy(48,3);
	printf("================");
	gotoxy(48,4);
	printf("REGISTRAR TURNO");
	gotoxy(48,5);
	printf("================");
	gotoxy(48,7);
	printf("Ingrese el ID del Medicos: ");
	scanf("%d",&buscar);
	
		prof=fopen("Profesional.dat","rb");
		fread(&Prof,sizeof(Profesionales),1,prof);
		while(!feof(prof))
		{
			if(buscar==Prof.IDprof && Prof.permisoP==3)
			{
				b=1;
				break;
			}
			else
			{
				fread(&Prof,sizeof(Profesionales),1,prof);
			}
		}
		fclose(prof);
		if(b==0)
		{
			gotoxy(48,9);
			printf("ID de Medicos no encontrada.");
			gotoxy(48,11);
			system("pause");
		}
		else{
			gotoxy(48,8);
			printf("Ingrese el DNI del Cliente: ");
			_flushall();
			gets(dnicliente);
			
			client=fopen("Clientes.dat","rb");
			fread(&Clien,sizeof(Cliente),1,client);
			while(!feof(client))
			{
				if(strcmp(dnicliente,Clien.Dni)==0)
				{
					c=1;
					gotoxy(48,9);
					printf("Nombre: %s",Clien.apeynom);
					break;
				}
				else
				{
					fread(&Clien,sizeof(Cliente),1,client);
				}
			}
			fclose(client);
			
			turn = fopen("Turnos.dat","a+b");
			
			if(c==1)
			{
			Turn.IDprof=buscar;
			strcpy(Turn.DNIcliente,dnicliente);
			strcpy(Turn.apeynom,Clien.apeynom);
			gotoxy(48,10);
			printf("Ingrese la fecha del turno.");
			gotoxy(75,10);
			scanf("%d",&Turn.FechaATENCION.dia);
			gotoxy(77,10);
			printf("/");
			gotoxy(78,10);
			scanf("%d",&Turn.FechaATENCION.mes);
			gotoxy(80,10);
			printf("/");
			gotoxy(81,10);
			scanf("%d",&Turn.FechaATENCION.anio);
			Turn.fueatendido=2;
			
			gotoxy(48,12);
			printf("======Turno registrado======");
			gotoxy(48,14);
			system("pause");
			fwrite(&Turn,sizeof(Turnos),1,turn);
		}
		else{
			marco();
			gotoxy(48,10);
			printf("Dni inexistente");
			gotoxy(48,12);
			system("pause");
		}
		fclose(turn);
	}
		
		
}
void Turnoss(Turnos Turn){
	FILE *turn;
	turn=fopen("Turnos.dat","rb");
	fread(&Turn,sizeof(Turnos),1,turn);
	while(!feof(turn)){
		marco();
		gotoxy(45,4);
		printf("Profesional: %d",Turn.IDprof);
		gotoxy(45,5);
		printf("Nombre paciente: %s",Turn.apeynom);
		gotoxy(45,6);
		printf("DNI: %s",Turn.DNIcliente);
		gotoxy(45,7);
		printf("Fecha: %d/%d/%d",Turn.FechaATENCION.dia,Turn.FechaATENCION.mes,Turn.FechaATENCION.anio);
		gotoxy(45,8);
		printf("Fue atendido %d",Turn.fueatendido);
		gotoxy(45,9);
		system("pause");
		system("cls");
		fread(&Turn,sizeof(Turnos),1,turn);
	}
	fclose(turn);
}
void Listatenc(FILE *turn, Turnos Turn, FILE *prof, Profesionales Prof,Cliente Clien) //solo lee las atenciones de un medico
{
	FILE *archCLI;
	FILE *archTUR;
	int dia=0,mes=0,anio=0,b=0,ID,c=0 ;
	marco();
	system("color 75");

	gotoxy(46,5);
	printf("Ingrese el ID del profesional: ");
	scanf("%d",&ID);
	prof=fopen("Profesional.dat","rb");
	fread(&Prof,sizeof(Profesionales),1,prof);
    while (!feof(prof))
    {
		if(ID==Prof.IDprof)
		{
			b=1;
			gotoxy(46,6);
			printf("PROFESIONAL: %s",Prof.apeynom);
		break;
		}
		else
		{
			fread(&Prof,sizeof(Profesionales),1,prof);
		}
    }
    fclose(prof);
    if(b==1)
	{
		gotoxy(46,7);
		printf("Ingrese la fecha: ");
		gotoxy(64,7);
		scanf("%d",&dia);
		gotoxy(66,7);
		printf("/");
		gotoxy(67,7);
		scanf("%d",&mes);
		gotoxy(69,7);
		printf("/");
		gotoxy(70,7);
		scanf("%d",&anio);
	
		archTUR=fopen("Turnos.dat","rb");
		archCLI=fopen("Clientes.dat","rb");
		fread(&Turn,sizeof(Turnos),1,archTUR);
		fread(&Clien,sizeof(Cliente),1,archCLI);
		while(!feof(archTUR))
		{
			if(Turn.IDprof==ID && Turn.FechaATENCION.dia==dia and Turn.FechaATENCION.mes==mes and Turn.FechaATENCION.anio==anio and Turn.fueatendido==1)
			{
				while(!feof(archCLI))
				{
				
					if(strcmp(Turn.DNIcliente,Clien.Dni)==0)
					{
						c=1;
						system("color 75");
						marco();
						gotoxy(46,9);
						printf("Cliente: ");
						puts(Clien.apeynom);
						gotoxy(46,10);
						printf("DNI Cliente: %s",Clien.Dni);
						gotoxy(46,11);
						printf("Peso: %.2f Kg",Clien.peso);
						gotoxy(46,12);
						printf("Edad: %d anios",2022-(Clien.fechadeNacimiento.anio));
						gotoxy(46,13);
						printf("Evolucion del Cliente: ");
						gotoxy(46,15);
						puts(Turn.DetalleAtencion);
						gotoxy(46,17);
						system("pause");
						system("cls");
					}
					fread(&Clien,sizeof(Cliente),1,archCLI);
				}
			}
		fread(&Turn,sizeof(Turnos),1,archTUR);	
	    }
    	fclose(archTUR);
    	fclose(archCLI);
	}
	else
	{
		gotoxy(46,9);
		printf("ID INCORRECTA");
		gotoxy(46,11);
		system("pause");
	}
	if(b==1 and c==0)
	{
		gotoxy(46,9);
		printf("No hay turnos en este fecha");
		gotoxy(46,11);
		system("pause");
	}
}

	

