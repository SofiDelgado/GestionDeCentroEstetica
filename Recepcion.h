struct Recepcionista
{
	int IDrecep,Dni;
	char apeynom[60],Telefono[60];
	char UsuarioR[60],ContraseniaR[50];
}Recep;

struct Profesionales
{
	int IDprof,Dni;
	char apeynom[60];
	char Tel[25];
	char UsuarioP[60],ContraseniaP[50];
}Prof;

struct fecha
{
	int dia,mes,anio;
};

struct Cliente
{
	char apeynom[60], Domicilio[60],Localidad[60],Telefono[25];
	int Dni;
	float peso;
	fecha fechadeNacimiento;
};Clien

struct Turnos
{
	int IDprof,DNIcliente;
	fecha FechaATENCION;
	char DetalleAtencion[60];
};Turn

void Regcliente (FILE *client, Cliente Clien)
{
	client = fopen ("Clientes.dat","ab");
	
	printf("\nIngrese el nombre del paciente: ");
		_flushall();
		gets(Clien.apeynom);
		
		printf("\nIngrese el domicilio del paciente: ");
		gets(Clien.Domicilio);
		
		printf("\nIngrese el DNI del paciente: ");
		scanf("%d",&Clien.Dni);
		
		printf("\nIngrese la localidad del paciente: ");
		_flushall();
		gets(Clien.Localidad);
		
		printf("\nIngrese la fecha de nacimiento del paciente.");
		
		printf("\nIngrese el dia: ");
		scanf("%d",&Clien.fechadeNacimiento.dia);
		printf("\nIngrese el mes: ");
		scanf("%d",&Clien.fechadeNacimiento.mes);
		printf("\nIngrese el anio: ");
		scanf("%d",&Clien.fechadeNacimiento.anio);
		
		printf("\nIngrese el peso del paciente (kg): ");
		scanf("%f",&Clien.peso); 
		
		printf("\nIngrese el telefono del paciente: ");
		_flushall();
		gets(Clien.Telefono);
		
		fwrite(&Clien,sizeof(Cliente),1,client);
		fclose(client);		
}

void Regturno (FILE *turn, Turnos Turn, FILE *prof, Profesionales Prof)
{
	int a;
	int b=0;
	
	prof = fopen("Profesionales.dat","rb");
		
		if(prof==NULL)
		{
			system("cls");
			printf("\nError, no se encontro el archivo.");
			exit(1);
		}
		
		printf("Ingrese el ID del profesional: ");
		scanf("%d",&a);
		
		fread(&Prof,sizeof(Profesionales),1,prof);
		while(!feof(prof))
		{
			if(a==Prof.IDprof)
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
			printf("\nID no encontrada.");
		}
		else
		{
			turn = fopen("Turnos.dat","ab");

			Turn.IDprof=Prof.IDprof;
			
			printf("Ingrese el DNI del paciente: ");
			scanf("%d",&Turn.DNIcliente);
			
			printf("\nIngrese la fecha del turno.");
			printf("\nIngrese el dia: ");
			scanf("%d",&Turn.FechaATENCION.dia);
			printf("\nIngrese el mes: ");
			scanf("%d",&Turn.FechaATENCION.mes);
			printf("\nIngrese el anio: ");
			scanf("%d",&Turn.FechaATENCION.anio);
			
			strcpy(Turn.DetalleAtencion,"vacio");
			
			printf("\n======Turno registrado======\n");
			fwrite(&Turn,sizeof(Turnos),1,turn);

			fclose(turn);
		}
}

void Listatenc(FILE *turn, Turnos Turn, FILE *prof, Profesionales Prof)
{
	
		turn=fopen("Turnos.dat","rb");
		prof=fopen("Profesionales.dat","rb");
		
		if(turn==NULL or prof==NULL)
		{
			printf("\nError al intentar abrir los archivos, contacte con el operador del sistema...");
			printf("\n\n");
			system("pause");
			exit(1);
		}
		
		fread(&Turn,sizeof(Turnos),1,turn);
	    fread(&Prof,sizeof(Profesionales),1,prof);
		
		printf("\nLista de atenciones");
		printf("\nMedicos");
		printf("\t\tFecha - Turno");
		printf("\n===========================================\n");
		
		while(!feof(turn))
		{
			printf("\n\n");
			if(Turn.IDprof==Prof.IDprof)
			{
				printf("%s",Prof.apeynom);
				printf("\t\t%d/%d/%d",Turn.FechaATENCION.dia, Turn.FechaATENCION.mes, Turn.FechaATENCION.anio);
			}
			fread(&Turn,sizeof(Turnos),1,turn);
	    	fread(&Prof,sizeof(Profesionales),1,prof);		
		}
		fclose(turn);
		fclose(prof);

}
