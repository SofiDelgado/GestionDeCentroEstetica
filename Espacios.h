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
	system("color 71");
	marco();
	int cont,Clienteencontrada=0, tamanoevolucion, evolucionregistrada,evolucionguardada=0,buscarID;
	char  DetalleEvolucion[380],dniPac[50]; bool atencion;
	
	archCLI=fopen("Clientes.dat","r+b");
	archTUR=fopen("Turnos.dat","r+b");
	
	//Verificar archivos correctos-----
	if(archCLI==NULL or archTUR==NULL)
	{
	system("color 71");
	marco();
	printf("Error en el sistema-Archivos no cargados");
	}	
	system("color 71");
	marco();
	gotoxy(46,8);
	printf("Ingrese ID del profesional: ");
	scanf("%d",&buscarID);
	gotoxy(46,9);
	printf("DNI: ");
	_flushall();
	gets(dniPac);
		
	//Registrar evolucion----		
		evolucionregistrada=0;
		
		fread(&regtur,sizeof(Turnos),1,archTUR);
		fread(&regcli,sizeof(Cliente),1,archCLI);
		while(!feof(archTUR) and evolucionregistrada==0)
		{
			if((strcmp(regtur.DNIcliente,dniPac)==0) and regtur.fueatendido==2)
			{
				while(!feof(archCLI) and evolucionregistrada==0)
				{
				 	if(strcmp(regcli.Dni,dniPac))
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
						//do 
						//{
							gotoxy(46,13);
							printf("Ingrese la evolucion de la Cliente en no mas de 380 letras:");
							_flushall();
							gets(DetalleEvolucion);   // (reg3.DetalleAtencion); 
							/*tamanoevolucion=strlen(DetalleEvolucion);//(reg3.DetalleAtencion);
							if(tamanoevolucion>380 or tamanoevolucion<5) //(tamanoevolucion>380)
							{
								gotoxy(46,17);
								printf("Debe escribir su evolucion de manera adecuada\n");
							}
							system("pause");
						}while(tamanoevolucion>380||tamanoevolucion<5);*/
						regtur.fueatendido=1;
						evolucionregistrada=1;
						system("cls");	
					}
			      fread(&regcli,sizeof(Cliente),1,archCLI);
				}
		    }
		    fwrite(&regtur,sizeof(Turnos),1,archTUR);
			fread(&regtur,sizeof(Turnos),1,archTUR);		  
	    }
    	fclose(archCLI);
    	fclose(archTUR);
    	
    	//Guardar evolucion-----	
    	
		if(Clienteencontrada!=1){
			system("color 71");
			marco();
			gotoxy(46,16);
			printf("El dni ingresado no esta registrado en sistema");
		}
		
		if(evolucionguardada=1){
			system("color 71");
			marco();
			gotoxy(46,19);
			printf("Ddatos cargados correctamente");
		}
	gotoxy(46,20);

}
void ListadeEspera(FILE *turn, Turnos Turn)
{


    int buscarID=0,hayturnos ;
	system("color 71");
	marco();
	gotoxy(45,4);
	
	turn=fopen("Turnos.dat","rb");
	
	fread(&Turn,sizeof(Turnos),1,turn);
	while(!feof(turn)){
		system("color 71");
		marco();
		if(Turn.fueatendido==2){
			hayturnos=1;
			gotoxy(45,6);
			printf("En espera");
			gotoxy(45,8);
			printf("DNI: %s ",Turn.DNIcliente);
			gotoxy(45,9);
			printf("Fecha: %d / %d / %d ",Turn.FechaATENCION.dia,Turn.FechaATENCION.mes,Turn.FechaATENCION.anio);
			gotoxy(45,10);
			printf("Historial: %s",Turn.DetalleAtencion);
			gotoxy(45,12);
			system("pause");
			system("cls");
		    fread(&Turn,sizeof(Turnos),1,turn);
	   }
	   fread(&Turn,sizeof(Turnos),1,turn);
	}
	   if(hayturnos==0)
		{
		system("color 71");
		marco();
		gotoxy(45,5);
		printf("No hay turnos en la fecha");
		gotoxy(45,7);
		system("pause");
		}
		
 
	fclose(turn);
    
}

