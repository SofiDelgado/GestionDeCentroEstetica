#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <strings.h>
#include<windows.h>
#include<gotoxy.h>
#include<Administracion.h>
#include<Recepcion.h>
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
	bool verificacion=false;
	
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
	//INICIO DE SESION
	system("color 70");
	gotoxy(52,7);
	//MARCO
	for (j=1; j < 6; j++) {
	  gotoxy(j, 1);
	  printf("%c", 177);
	  gotoxy(j, 24);
	  printf("%c",177);
	 }
	login(prof,recep,Prof,Recep,permiso,verificacion);

	if(permiso==1 and verificacion==true)
	{
		system("cls");
		MenuAdmin(prof,Prof,recep,Recep);
	}
	else
	{
		if(permiso==2 and verificacion==true)
		{
		system("cls");
		MenuRecepcionista(client,Clien,prof,Prof,turn,Turn);
		}
		else
		{	
			if(permiso==3 and verificacion==true)
			{
			
			}
			else
			{
				gotoxy(45,14);
				printf("No inicio sesion...");
			}
		}
	}
}

