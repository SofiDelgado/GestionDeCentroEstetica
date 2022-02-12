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
