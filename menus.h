void MenuAdmin(FILE *arch,Profesionales Prof,Recepcionista Recep)
{
	int op;
	int a;
	do{
	printf("\nADMINISTRACION");
	printf("\n1)Registrar profesional");
	printf("\n2)Registrar Usuario Recepcionista");
	printf("\n3)Atenciones por Profesional");
	printf("\n4)Ranking de Profesionales por Atenciones");
	printf("\n5)ver profecionales");
	printf("\n6)Salir\nOpcion: ");
	scanf("%d", &op);
	switch(op)
	{
		case 1:
		system("cls");
		CargarProfesional(arch,Prof);
		break;
		case 2:
		system("cls");
		CargarRecepcionista(arch,Recep);
		break;
		case 3: break;
		case 4: break;
		case 5:
		system("cls");
		ver(arch,Prof);
		break;
		case 6: break;
		default: printf("\nERROR...\n"); break;
	}
	}while(op!=6);
	
}
void MenuRecep(FILE *client,Cliente Clien,FILE *prof, Profesionales Prof, FILE* turn, Turnos Turn)
{
	int Opc;
	
	do
	{
		printf("Modulo del recepcionista\n");
		printf("==========================");
		printf("\n1.- Registrar Cliente");
		printf("\n2.- Registrar Turno");
		printf("\n3.- Listado de Atenciones por Profesional y Fecha\n");
		printf("\n4.- Cerrar la aplicacion.\n");
		printf("Ingrese una opcion: _");
		scanf("%d", &Opc);
		
		switch(Opc)
		{
			case 1:
			system("CLS");
			Regcliente(client,Clien);
			break;
	        
	        case 2:
	        system("CLS");
	        Regturno(turn, Turn, prof, Prof);
	        break;
	        
	        case 3:
	        system("CLS");
	        Listatenc(turn, Turn, prof, Prof);	
	        
	        case 4:
	        system("CLS");
	        printf("Saliendo de la aplicacion...");
	        break;
	        
	        default:
	        printf("Error, ingrese una opcion valida.");
	        break;
	        
		}
		
	}while(Opc!=4);
}

void MenuEspacios (FILE *prof,Profesionales Prof,FILE *turn,Turnos Turn)
{
	do{
		printf ("\n\tModulo Espacios");
			printf("\n\t--------------\n");
			printf ("\n\t\t1.- Iniciar Sesion");
			printf ("\n\t\t2.- Visualizar Lista de Espera de Turnos");
			printf ("\n\t\t3.- Registrar Evolución del tratamiento");
			printf ("\n\t\t4.- Cerrar la aplicacion.");
			
			printf ("\nIngrese la opcion: ");
			scanf("%d",&op);
			
	switch(op){
		case 1:			

			break;						
		case 2:
			if(iniciar){
				turn=fopen( "Profesionales.dat" , "w+b" );
				fread(&Turn,sizeof(Turnos),1,turn);
				printf("\n\tIngrese la fecha(2022)");
				printf("\tDia: ");
				scanf("%d",&reg.fec.dia);
				printf("\tMes: ");
				scanf("%d",&reg.fec.mes);
				printf("\tLista de espera:\n");
				int verDia, verMes,e=1;;
				while(!feof(turn)){
					verDia=strcmp(reg.fec.dia,Turn.FechaATENCION.dia);
					verMes=strcmp(reg.fec.mes,Turn.FechaATENCION.mes);
					if(verDia ==0 && verMes==0){
						while(!feof(Turn)){
							printf("\n\t%d.-",e);
							puts(Turn.apeynom);//nombre
							e++;
						}
					}else{
						printf("\nNo hay turnos registrados para la fecha.");
					}
					
				}
			}else{
				printf("\n\tNo se pudo iniciar sesion correctamente");
			}
			system("PAUSE");
			break;
		case 3:
			if(iniciar){
				prof=fopen( "Profesionales.dat" , "w+b" );
				fread(&Prof,sizeof(Profesionales),1,prof);
				progreso(reg);		
			}else{
				printf("\n\tNo se pudo iniciar sesion correctamente");
			}
			break;
			
		case 4:
			rep=false;
            break;
		default:
			printf("\n La opcion elegida no pertence al menu. Por favor elija una de las opciones del menu. Gracias...\n");
		    	system ("PAUSE");
			break;
	}
	}while(rep==true);

}
