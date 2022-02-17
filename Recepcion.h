void Regcliente(FILE *client,Cliente Clien){
	system("color 75");
	marco();
	
	client = fopen ("Clientes.dat","a+b");
	gotoxy(48,3);
	printf("=====================");
	gotoxy(48,4);
	printf("REGISTRAR CLIENTE");
	gotoxy(48,5);
	printf("=====================");
	gotoxy(48,7);
	printf("Ingrese el nombre del Cliente: ");
	_flushall();
	gets(Clien.apeynom);
	gotoxy(48,8);
	printf("Ingrese el domicilio del Cliente: ");
	gets(Clien.Domicilio);
	gotoxy(48,9);
	printf("Ingrese el DNI del Cliente: ");
	_flushall();
	gets(Clien.Dni);
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
	fclose(client);		
}

void Regturno (FILE *turn, Turnos Turn, FILE *prof, Profesionales Prof)
{
	FILE *arch;
	FILE *client;
	int a,aux;
	int b=0,c=0;
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
	printf("Ingrese el ID del profesional: ");
	scanf("%d",&a);
	
	prof = fopen("Profesional.dat","rb");
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
			a=Turn.IDprof;
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
					
					break;
				}
				else
				{
					fread(&Clien,sizeof(Cliente),1,client);
				}
			}
			fclose(client);
			turn = fopen("Turnos.dat","ab");
			if(c==1)
			{
			strcpy(Turn.DNIcliente,dnicliente);
			gotoxy(48,9);
			printf("Ingrese el nombre y apellidodel Cliente: ");
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
			Turn.fueatendido=2;
			strcpy(Turn.DetalleAtencion,"vacio");
			
			gotoxy(48,15);
			printf("======Turno registrado======");
			gotoxy(48,17);
			system("pause");
			fwrite(&Turn,sizeof(Turnos),1,turn);
		}
		else{
			system("cls");
			gotoxy(45,6);
			printf("Dni inexistente");
			gotoxy(45,8);
			system("pause");
		}

			fclose(turn);
		}
}
void Listatenc(FILE *turn, Turnos Turn, FILE *prof, Profesionales Prof) //solo lee las atenciones de un medico
{
		turn=fopen("Turnos.dat","rb");
		prof=fopen("Profesionales.dat","rb");
		
		fread(&Turn,sizeof(Turnos),1,turn);
	    fread(&Prof,sizeof(Profesionales),1,prof);
			while(!feof(turn)){
				system("color 75");
				marco();
				if(Turn.IDprof==Prof.IDprof){
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
					gotoxy(59,7);
					printf("%s",Prof.apeynom);
					gotoxy(48,9);
					printf("%d/%d/%d",Turn.FechaATENCION.dia, Turn.FechaATENCION.mes, Turn.FechaATENCION.anio);
					gotoxy(48,12);
					system("pause");
				}
				system("cls");
			fread(&Turn,sizeof(Turnos),1,turn);
		    fread(&Prof,sizeof(Profesionales),1,prof);		
		}
		fclose(turn);
		fclose(prof);
	

}
/*void Listatenc(FILE *turn, Turnos Turn, FILE *prof, Profesionales Prof) //solo lee las atenciones de un Profesional
{
	 	int Buscador,j=0,AnioBuscar,MesBuscar,DiaBuscar,Repetidor;
		FILE *Auxiliar = fopen ("Auxiliar.dat","w+b");
		turn=fopen("Turnos.dat","rb");
		
		if(turn==NULL)
		{
		system("color 75");
		marco();
		gotoxy(30,4);
		printf("Error al intentar abrir los archivos, contacte con el operador del sistema...");
		gotoxy(30,6);
		system("pause");
		}
		OtroIntento:
			printf("Ingrese la ID del profesional para ver su lista de evolucion de sus pacientes: ");
		    scanf("%d",&Buscador);
		    fflush(stdin);
		    printf("Ingrese el dia del turno del paciente: ");
		    scanf("%d",&DiaBuscar);
		    fflush(stdin);
		    printf("Ingrese el mes del turno del paciente: ");
		    scanf("%d",&MesBuscar);
		    fflush(stdin);
		    printf("Ingrese el anio del turno del paciente: ");
		    scanf("%d",&AnioBuscar);
  
				 while (!feof(turn)){
		        fread (&Turn,sizeof(Turnos),1,turn);
		        if (Buscador == Turn.IDprof && Turn.fueatendido == 1 && Turn.FechaATENCION.dia == DiaBuscar && Turn.FechaATENCION.mes == MesBuscar && Turn.FechaATENCION.anio == AnioBuscar){        
					fwrite(&Turn,sizeof(Turnos),1,Auxiliar);
		          j++;
		        }
		    }
		
		    if (j!= 0){
		        rewind (Auxiliar);
		        fread(&Turn,sizeof(Turnos),1,Auxiliar);
		        printf("El profesional %d tiene %d pacientes atendidos y sus evoluciones son: \n",Turn.IDprof,j);
		        printf("DNI Paciente: %d\nSu detalle de atencion es: ",Turn.DNIcliente);
		        _flushall();
				gets(Turn.DetalleAtencion);
		        for (int i = 1; i < j; i++){
		            fread(&Turn,sizeof(Turnos),1,Auxiliar);
		            printf("DNI: %d\nSu detalle de atencion es: %s",Turn.DNIcliente,Turn.DetalleAtencion);
		        }
		        system("pause");
		    }else{
		        printf("No se pudo encontrar ningun doctor que haya tenido un cliente esa fecha.Si se equivoco en algunos de los datos y quiere volver a intentar ingrese 1: ");
		        scanf("%d",&Repetidor);
		        if(Repetidor == 1){
		            goto OtroIntento;
		        }
		    }
		    
		fclose(turn);

	}*/
	

