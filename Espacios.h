#define TRUE 1
#define FALSE 0
struct fechA{
	int dia,mes,anio;
};
struct registro{
	char avance[380], doc[60];
	fecha fec;
	fechA fechAtencion;
	bool borrado;
	
}reg;

void RegistroEvolucionCliente(FILE*archTUR,FILE *archCLI,Cliente regcli,Turnos regtur)
{
	FILE *arch;
	Profesionales Prof;
	int b=0,c=0,cont,Clienteencontrada=0,evolucionregistrada,evolucionguardada=0,buscarID;
	char  DetalleEvolucion[380],dniPac[50];
	int dia=0,mes=0,anio=0,t=0 ;
	marco();
    gotoxy(46,4);
	printf("Ingrese la fecha: ");
	gotoxy(64,4);
	scanf("%d",&dia);
	gotoxy(66,4);
	printf("/");
	gotoxy(67,4);
	scanf("%d",&mes);
	gotoxy(69,4);
	printf("/");
	gotoxy(70,4);
	scanf("%d",&anio);
	system("color 71");

	gotoxy(46,5);
	printf("Ingrese ID del profesional: ");
	scanf("%d",&buscarID);

	arch=fopen("Profesional.dat","r+b");
	fread(&Prof,sizeof(Profesionales),1,arch);
    while (!feof(arch))
    {
		if(buscarID==Prof.IDprof && Prof.permisoP==3)
		{
			b=1;
			gotoxy(46,7);
			printf("Profesional: %s",Prof.apeynom);
		break;
		}
		else
		{
			fread(&Prof,sizeof(Profesionales),1,arch);
		}
    }
    fclose(arch);
    
    if(b==1)
	{
		gotoxy(46,8);
		printf("DNI: ");
		_flushall();
		gets(dniPac);
		//Registrar evolucion----		;
		evolucionregistrada=0;	
		
		archTUR=fopen("Turnos.dat","r+b");
		archCLI=fopen("Clientes.dat","r+b");
		fread(&regtur,sizeof(Turnos),1,archTUR);
		fread(&regcli,sizeof(Cliente),1,archCLI);
		while(!feof(archTUR) && evolucionregistrada==0)
		{
			if(regtur.IDprof==buscarID && (strcmp(regtur.DNIcliente,dniPac)==0) && regtur.FechaATENCION.dia==dia and regtur.FechaATENCION.mes==mes and regtur.FechaATENCION.anio==anio and regtur.fueatendido==2)
			{
				while(!feof(archCLI) and evolucionregistrada==0)
				{
				 	if(strcmp(dniPac,regcli.Dni)==0)
					{
						system("color 71");
						marco();
						Clienteencontrada=1;
						gotoxy(46,9);
						printf("Cliente: ");
						puts(regcli.apeynom);
						gotoxy(46,10);
						printf("Peso: %.2f Kg",regcli.peso);
						gotoxy(46,11);
						printf("Edad: %d anios",2022-(regcli.fechadeNacimiento.anio));
						gotoxy(46,12);
						printf("DNI Cliente: %s",regcli.Dni);
						gotoxy(46,13);
						printf("Ingrese la evolucion de la Cliente:");
						_flushall();
						gets(DetalleEvolucion);
						evolucionregistrada=1;
					}
			      fread(&regcli,sizeof(Cliente),1,archCLI);
				}
			}
			else
			{
			fread(&regtur,sizeof(Turnos),1,archTUR);	
			}
	    }
    	fclose(archTUR);
    	fclose(archCLI);
   	}
	else
	{
		system("cls");
		marco();
		gotoxy(48,6);
		printf("ID inexistente");
		gotoxy(48,8);
		system("pause");
	}
    	//Guardar evolucion-----
			
		archTUR=fopen("Turnos.dat","r+b");
		if(Clienteencontrada==1){
			cont=0;
			do{	
				fread(&regtur,sizeof(Turnos),1,archCLI);
					if(regtur.IDprof==buscarID)
					{
						regtur.fueatendido=1;
						strcat(regtur.DetalleAtencion," / ");
						strcat(regtur.DetalleAtencion,DetalleEvolucion);
						fseek(archTUR,cont*sizeof(Turnos),SEEK_SET);
						fwrite(&regtur,sizeof(Turnos),1,archTUR);
						evolucionguardada=1;
					}
				cont++;
			}while(regtur.IDprof!=buscarID);
		}
		fclose(archTUR);
			
		if(evolucionguardada==1){
			system("color 71");
			marco();
			gotoxy(46,19);
			printf("Datos cargados correctamente");
			gotoxy(46,21);
			system("pause");
		}
}
void ListadeEspera(FILE *turn, Turnos Turn)
{
    int hayturnos,dia,mes,anio ;
    marco();
    gotoxy(45,4);
	printf("Ingrese la fecha: ");
	gotoxy(63,4);
	scanf("%d",&dia);
	gotoxy(65,4);
	printf("/");
	gotoxy(66,4);
	scanf("%d",&mes);
	gotoxy(68,4);
	printf("/");
	gotoxy(69,4);
	scanf("%d",&anio);
	
	turn=fopen("Turnos.dat","rb");
	fread(&Turn,sizeof(Turnos),1,turn);
	while(!feof(turn)){
		if(Turn.FechaATENCION.dia==dia and Turn.FechaATENCION.mes==mes and Turn.FechaATENCION.anio==anio and Turn.fueatendido==2)
		{
			system("color 71");
			marco();
			hayturnos=1;
			gotoxy(45,6);
			printf("En espera");
			gotoxy(45,8);
			printf("MEDICO: %d ",Turn.IDprof);
			gotoxy(45,9);
			printf("NOMBRE: %s",Turn.apeynom);
			gotoxy(45,10);
			printf("DNI: %s ",Turn.DNIcliente);
			gotoxy(45,11);
			printf("Fecha: %d / %d / %d ",Turn.FechaATENCION.dia,Turn.FechaATENCION.mes,Turn.FechaATENCION.anio);
			gotoxy(45,12);
			printf("Historial: %s",Turn.DetalleAtencion);
			gotoxy(45,13);
			system("pause");
			system("cls");
			fread(&Turn,sizeof(Turnos),1,turn);
 		}
 		else{
	   		fread(&Turn,sizeof(Turnos),1,turn);
			}
	}
	fclose(turn);
	if(hayturnos==0)
	{
	system("color 71");
	marco();
	gotoxy(45,5);
	printf("No hay turnos en la fecha");
	gotoxy(45,7);
	system("pause");
	}
    
}
