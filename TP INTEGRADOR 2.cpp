#include<stdio.h>
#include <stdlib.h>
#include <strings.h>
#include<windows.h>
#include<Administracion.h>
#include<menus.h>
#include<gotoxy.h>
#include<Login.h>
#include<Recepcion.h>

main(){
	FILE*prof;
	FILE*recep;
	FILE*client;
	FILE *turn;
	int op;
	int permiso;
	bool verificacion=false;
	
	//INICIO DE SESION
	login(prof,recep,Prof,Recep,permiso,verificacion);
	//MenuAdmin(prof,Prof,Recep);
	
	if(permiso==1 and verificacion==true)
	{
		system("cls");
		MenuAdmin(prof,Prof,Recep);
	}
	else
	{
		printf("\nNo inicio sesion");
	}
	if(permiso==2)
	{
		system("cls");
		MenuRecep(client,clien,prof,Prof,turn,Turn);
	}
	else
	{
		printf("\nNo inicio sesion");
	}
	if(permiso==3)
	{
	
	}
	else
	{
		printf("\nNo inicio sesion");
	}
}

