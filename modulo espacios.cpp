#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

struct fecha{
	int dia,mes,anio;
};
struct fechA{
	int dia,mes,anio;
};
struct cliente{ /*LO PASAN*/
	char nomApe[60];
	int dni;
	float peso;
	fecha fechadeNacimientoNaci;
};
struct registro{
	//nombre de usuario 
	//contra
	char avance[380], doc[60];
	cliente cli;
	fecha fec;
	fechA fechAtencion;
	bool borrado;
	
};
void progreso(registro reg);
main(){
	registro reg;
	FILE *arch;
	char rep=true, nombreUs[10],contra[10];
	int op, valor,valoR;
	
	do{
		printf ("\n\tModulo Espacios");
			printf("\n\t--------------\n");
			printf ("\n\t\t1.- Iniciar Sesion");
			printf ("\n\t\t2.- Visualizar Lista de Espera de Turnos (informe)");
			printf ("\n\t\t3.- Registrar Evolución del tratamiento");
			printf ("\n\t\t4.- Cerrar la aplicacion.");
			
			printf ("\nIngrese la opcion: ");
			scanf("%d",&op);
			
	switch(op){
		case 1:			
			//abrir archivo con los doctores
			//arch=fopen("empleados.dat","w+b");
			printf ("\tNombre de usuario: ");
			_flushall();
			gets(nombreUs);
			printf ("\tContraseña: ");
			_flushall();
			gets(contra);
			while(!feof(arch)){  /*arch VER Y CAMBIAR*/
				//valor=strcmp(nombreUs,);
				//valoR=strcmp(contra,);
				if(valor==0){
					if(valoR==0){
						//abrir archivo con los pacientes
						//arch=fopen("empleados.dat","w+b");
					}else{
						printf("Contraseña incorrecta");
						break;
					}
				
				}else{
					printf("Usuario incorrecto");
					break;
				}
				fread(&reg, sizeof(registro),1,arch);
			}
										
		case 2:
			//mpstrar lista
			//arch=fopen("empleados.dat","r+b");
			//fread(&reg, sizeof(registro),1,arch);
			printf("\tLista de espera:\n");
			int pa=1;
			while(!feof(arch)){  /*arch VER Y CAMBIAR*/
				printf("\n\t\t%d.-%s",pa,reg.cli.nomApe); //ver 
				pa++;
				fread(&reg, sizeof(registro),1,arch);
			}
			system("PAUSE");
			break;
		case 3:
			//arch=fopen("empleados.dat","r+b");
			//fread(&reg, sizeof(registro),1,arch);
			progreso(reg);
			//con paciente X mostrar el progreso
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

//mostrar listado de clientes que seran atendidos hoy
void progreso(registro reg){
	char nomApePac[60], domiPac[60];
	int dniPac,valorDoc,valoRDoc;
	float pesoPac;
	FILE *arch;
	//pedir apellido, dni,dom,edad,peso
	printf("\tDATOS DEL PACIENTE");
	printf("\n\t\tNombre y apellido: ");
	_flushall();
	gets(nomApePac);
	printf("\t\tDNI: ");
	scanf("%d",&dniPac);
/*	printf("\t\tDomicilio: ");
	_flushall();
	gets(domiPac);
	printf("\t\tFecha de nacimiento: ");
	scanf("%d",&dniPac);*/
	while(!feof(arch)){  /*arch VER Y CAMBIAR*/
		//valorDoc=strcmp(nombreUs,);
		//valoRDoc=strcmp(contra,);
		if(valorDoc==0){
			if(valoRDoc==0){
				//abrir archivo con los pacientes
				//arch=fopen("empleados.dat","w+b");
				//mostrar apellido, dni,dom,edad,peso
				printf("\nRegistre los avances del paciente:\n\t");
				_flushall();
				gets(reg.avance);
				printf("\nIngrese la fecha del dia en el que el paciente fue atendido (2022)");
				printf("\tDia: ");
				scanf("%d",&reg.fec.dia);
				printf("\tMes: ");
				scanf("%d",&reg.fec.mes);
				printf("\nIngrese el nombre del doctor: ");
				_flushall();
				gets(reg.doc);
			}else{
				printf("\nPACIENTE NO REGISTRADO");
				break;
			}
		}else{
			printf("\nPACIENTE NO REGISTRADO");
			break;
		}
		fread(&reg, sizeof(registro),1,arch);
	}
	strcopy

}


