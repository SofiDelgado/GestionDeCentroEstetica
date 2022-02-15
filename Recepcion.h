void Regcliente(FILE *client,Cliente Clien)
{
	system("color 75");
	marco();
	
	client = fopen ("Clientes.dat","ab");
	gotoxy(48,3);
	printf("=====================");
	gotoxy(48,4);
	printf("REGISTRAR CLIENTE");
	gotoxy(48,5);
	printf("=====================");
	gotoxy(48,7);
	printf("Ingrese el nombre del paciente: ");
	_flushall();
	gets(Clien.apeynom);
	gotoxy(48,8);
	printf("Ingrese el domicilio del paciente: ");
	gets(Clien.Domicilio);
	gotoxy(48,9);
	printf("Ingrese el DNI del paciente: ");
	_flushall();
	gets(Clien.Dni);
	gotoxy(48,10);	
	printf("Ingrese la localidad del paciente: ");
	_flushall();
	gets(Clien.Localidad);
	gotoxy(48,11);
	printf("Ingrese la fecha de nacimiento del paciente.");
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
	printf("Ingrese el peso del paciente (kg): ");
	scanf("%f",&Clien.peso); 
	gotoxy(48,16);
	printf("Ingrese el telefono del paciente: ");
	_flushall();
	gets(Clien.Telefono);
	
	fwrite(&Clien,sizeof(Cliente),1,client);
	fclose(client);		
}

void Regturno (FILE *turn, Turnos Turn, FILE *prof, Profesionales Prof)
{
	int a;
	int b=0;
	system("color 75");
	marco();
	prof = fopen("Profesionales.dat","rb");
		
		if(prof==NULL)
		{
			system("cls");
			printf("\nError, no se encontro el archivo.");
		}
		gotoxy(48,3);
		printf("================");
		gotoxy(48,4);
		printf("REGISTRAR TURNO");
		gotoxy(48,5);
		printf("================");
		gotoxy(48,7);
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
			gotoxy(48,8);
			printf("ID no encontrada.");
			gotoxy(48,9);
			system("pause");
		}
		else
		{
			turn = fopen("Turnos.dat","ab");

			Turn.IDprof=Prof.IDprof;
			gotoxy(48,8);
			printf("Ingrese el DNI del paciente: ");
			_flushall();
			gets(Turn.DNIcliente);
			gotoxy(48,9);
			printf("Ingrese el nombre y apellidodel paciente: ");
			_flushall();
			gets(Turn.apeynom);
			gotoxy(48,10);
			printf("Ingrese la fecha del turno.");
			gotoxy(48,11);
			printf("Ingrese el dia: ");
			scanf("%d",&Turn.FechaATENCION.dia);
			gotoxy(48,12);
			printf("Ingrese el mes: ");
			scanf("%d",&Turn.FechaATENCION.mes);
			gotoxy(48,13);
			printf("Ingrese el anio: ");
			scanf("%d",&Turn.FechaATENCION.anio);
			
			strcpy(Turn.DetalleAtencion,"vacio");
			gotoxy(48,15);
			printf("======Turno registrado======");
			gotoxy(48,17);
			system("pause");
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
		system("color 75");
		marco();
		gotoxy(30,4);
		printf("Error al intentar abrir los archivos, contacte con el operador del sistema...");
		gotoxy(30,6);
		system("pause");
		}
		else
		{
		fread(&Turn,sizeof(Turnos),1,turn);
	    fread(&Prof,sizeof(Profesionales),1,prof);
			while(!feof(turn))
			{
				if(Turn.IDprof==Prof.IDprof)
				{	system("color 75");	
					marco();
					gotoxy(48,3);
					printf("====================");
					gotoxy(48,4);
					printf("LISTA DE ATENCIONES");
					gotoxy(48,5);
					printf("====================");
					gotoxy(48,7);
					printf("Medicos: ");
					gotoxy(48,8);
					printf("Fecha - Turno");
					gotoxy(58,7);
					printf("%s",Prof.apeynom);
					gotoxy(48,9);
					printf("%d/%d/%d",Turn.FechaATENCION.dia, Turn.FechaATENCION.mes, Turn.FechaATENCION.anio);
					gotoxy(48,12);
					system("pause");
				}
				fread(&Turn,sizeof(Turnos),1,turn);
		    	fread(&Prof,sizeof(Profesionales),1,prof);		
		    	system("cls");
		    	system("pause");
			}
			fclose(turn);
			fclose(prof);
	}
	

}
