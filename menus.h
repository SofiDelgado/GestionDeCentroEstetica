void MenuAdmin(FILE *arch,Profesionales Prof,FILE *recep,Recepcionista Recep,Atenciones Aten,FILE *turn,Turnos Turn)
{
	int op,a,j;

	  
	do{
		system("color 74");
		//marco
		for (j=1; j < 120; j++) {
		gotoxy(j, 1);
		printf("%c", 177);
		gotoxy(j, 24);
		printf("%c",177);
		}
		int d;
		for (d = 2; d < 24; d++) {
		gotoxy(1, d);
		printf("%c", 179);
		gotoxy(119, d);
		printf("%c", 179);
		}
		gotoxy(1, 1);
		printf("%c", 223);
		gotoxy(119, 1);
		printf("%c",223);
		gotoxy(1, 24);
		printf("%c", 223);
		gotoxy(119, 24);
		printf("%c", 223);
		//fin marco
		gotoxy(44,2);
		printf("=======================");
		gotoxy(44,3);
		printf("MODULO ADMINISTRACION");
		gotoxy(44,4);
		printf("=======================");
		gotoxy(44,6);
		printf("1.-Registrar profesional");
		gotoxy(44,7);
		printf("2.-Registrar Usuario Recepcionista");
		gotoxy(44,8);
		printf("3.-Atenciones por Profesional");
		gotoxy(44,9);
		printf("4.-Ranking de Profesionales por Atenciones");
		gotoxy(44,10);
		printf("5.-ver usuarios registrados");
		gotoxy(44,11);
		printf("6.-Salir");
		gotoxy(44,12);
		printf("Opcion: ");
		scanf("%d", &op);
	switch(op)
	{
		case 1:
		system("cls");
		CargarProfesional(arch,Prof);
		system("cls");
		break;
		case 2:
		system("cls");
		CargarRecepcionista(arch,Recep);
		system("cls");
		break;
		case 3:
		system("cls");
		atenciones(turn,Turn);
		system("cls");
		break;
		case 4:
		system("cls");
		ranking(Prof,Turn,Aten);
		system("cls");
		break;
		case 5:
		system("cls");
		ver(arch,Prof,recep,Recep);
		system("cls");
		break;
		case 6: 
		break;
		default:
		gotoxy(49,9);
		printf("ERROR...");
		gotoxy(49,10);
		system("pause"); 
		system("cls");
		break;
	}
	}while(op!=6);
	
}
void MenuRecep(FILE *client,Cliente Clien,FILE *prof, Profesionales Prof, FILE* turn, Turnos Turn,Atenciones Aten)
{
	int Opc;
	
	do
	{
		system("color 75");
		marco();
		gotoxy(44,2);
		printf("=====================");
		gotoxy(44,3);
		printf("MODULO RECEPCIONISTA");
		gotoxy(44,4);
		printf("=====================");
		gotoxy(44,6);
		printf("1.-Registrar Cliente");
		gotoxy(44,7);
		printf("2.-Registrar Turno");
		gotoxy(44,8);
		printf("3.-Listado de Atenciones por Profesional y Fecha");
		gotoxy(44,9);
		printf("4.-Cerrar la aplicacion.");
		gotoxy(44,10);
		printf("Ingrese una opcion: ");
		scanf("%d", &Opc);
		
		switch(Opc)
		{
			case 1:
			system("CLS");
			Regcliente(client,Clien);
			system("CLS");
			break;
	        case 2:
	        system("CLS");
	        Regturno(turn, Turn, prof, Prof);
	        system("CLS");
	        break;
	        case 3:
	        system("CLS");
	        Listatenc(turn, Turn, prof, Prof);
			system("CLS");
	        case 4:
	        break;
	        default:
	        system("cls");
	        gotoxy(49,9);
			printf("ERROR...");
			gotoxy(49,10);
			system("pause"); 
	        break;
		}
		
	}while(Opc!=4);
}

void MenuEspacios (FILE *prof,Profesionales Prof,FILE *turn,Turnos Turn, FILE *client)
{
	int op;
	char rep=true;
	do{
		system("color 71");
		marco();
		gotoxy(44,2);
		printf("=====================");
		gotoxy(44,3);
		printf ("MODULO ESPACIOS");
		gotoxy(44,4);
		printf("=====================");
		gotoxy(44,6);
		printf ("1.-Visualizar Lista de Espera de Turnos");
		gotoxy(44,7);
		printf ("2.-Registrar Evolución del tratamiento");
		gotoxy(44,8);
		printf ("3.-Cerrar la aplicacion.");
		gotoxy(44,9);
		printf ("Ingrese la opcion: ");
		scanf("%d",&op);

	switch(op){
		case 1:
			system("CLS");
			ListadeEspera(turn,Turn);
			system("CLS");	
			break;						
		case 2:
			system("CLS");
			EvolucionTrat(prof,Prof,reg,client,turn);
			system("PAUSE");
			system("CLS");
			break;
		case 3:

            break;
		default:
			system("cls");
			gotoxy(49,9);
			printf("ERROR...");
			gotoxy(49,10);
			system("pause"); 
			system("cls");
		break;
	}
	}while(rep==true);

}
