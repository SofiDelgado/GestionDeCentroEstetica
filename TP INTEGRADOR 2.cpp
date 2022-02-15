#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <strings.h>
#include<windows.h>
#include<gotoxy.h>
#include<marco.h>
#include<Administracion.h>
#include<Recepcion.h>
#include<Espacios.h>
#include<menus.h>
#include<Login.h>

/*
colores
0=negro
1=azul
3=aguamarina
4=rojo
5=purpura
6=amarillo
7=blanco
8=gris
9=azul claro
A=verde claro
B=aguamarina claro
C=rojo claro
D=purpura claro
E=amarillo claro
F=blanco brillante
*/
main(){
	FILE*prof;
	FILE*recep;
	FILE*client;
	FILE*turn;
	int op,j;
	int permiso;
	 
	do{
		bool verificacion=false;
		system("color 70");
		marco();
		gotoxy(48,2);
		printf("==================");
		gotoxy(48,3);
		printf("CENTRO DE ESTETICA");
		gotoxy(48,4);
		printf("==================");
		gotoxy(49,6);
		printf("1)INICIAR SESION");
		gotoxy(49,7);
		printf("2)SALIR");
		gotoxy(49,8);
		printf("Opcion:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			system("cls");
			login(prof,recep,Prof,Recep,permiso,verificacion);
			//MENUS
			if(permiso==1 and verificacion==true)
			{
				system("cls");
				MenuAdmin(prof,Prof,recep,Recep,Aten,turn,Turn);
			}
			else
			{
				if(permiso==2 and verificacion==true)
				{
				system("cls");
				MenuRecep(client,Clien,prof,Prof,turn,Turn,Aten);
				}
				else
				{	
					if(permiso==3 and verificacion==true)
					{
						system("cls");
						MenuEspacios(prof,Prof,turn,Turn,client);
					}
					else
					{
						gotoxy(49,15);
						printf("No inicio sesion...");	
						gotoxy(49,17);
						system("pause");
					}
				}
			}
			system("cls");
			break;
			case 2:
			
			system("cls");
			gotoxy(49,15);
			printf("Saliendo...");
			break;

			default: 
			gotoxy(49,9);
			printf("ERROR...");
			gotoxy(49,10);
			system("pause"); 
			system("cls");
			break;
		}
	}while(op!=2);
}

