#include<stdio.h>
#include <stdlib.h>
#include <strings.h>
#include<windows.h>
#include<Administracion.h>
#include<menus.h>
#include<gotoxy.h>
#include<Login.h>

main(){
	FILE*arch;
	int op,contarusuarioR;
	
	//login(arch,Prof,Recep,contarusuarioR);
	do{
	/*if(Prof.permisoP==1 or )
	{*/
	printf("\n1)ADMINISTRACION");
	printf("\n2)RECEPCION");
	printf("\n3)ESPACIOS");
	printf("\n4)Salir\nOpcion: ");
	scanf("%d", &op);
	/*}
	if(Usu.Us==2)
	{
	printf("\n1)RECEPCION");
	printf("\n2)Salir\nOpcion: ");
	scanf("%d", &op);
	}
	if(Usu.Permiso==3)
	{
	printf("\n1PROFECIONAL");
	printf("\n2)Salir\nOpcion: ");
	scanf("%d", &op);
	}*/
	switch(op)
	{
		case 1:
		system("cls");
		MenuAdmin(arch,Prof,Recep,contarusuarioR);
		break;
		case 2:system("cls");
		break;
		case 3:
		system("cls");
		break;
		case 4: break;
		default: printf("\nERROR...\n"); break;
	}
	}while(op!=4);
}

