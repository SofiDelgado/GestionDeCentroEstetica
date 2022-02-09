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
void MenuRecepcion()
{
	
}
