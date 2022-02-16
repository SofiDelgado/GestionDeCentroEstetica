#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <strings.h>
#include<windows.h>
#include<gotoxy.h>
#include<marco.h>
struct Recepcionista{
	int IDrecep,Dni,permisoR;
	char apeynom[60],Tel[60];
	char UsuarioR[60],ContraseniaR[50];
}Recep;
struct Profesionales{
	int IDprof,Dni,permisoP;
	char apeynom[60];
	char Tel[25];
	char UsuarioP[60],ContraseniaP[50];
}Prof;
struct fecha{
	int dia,mes,anio;
};
struct Cliente{
	char apeynom[60], Domicilio[60],Localidad[60],Telefono[25],Dni[50];
	float peso;
	fecha fechadeNacimiento;
}Clien;
struct Turnos{
	int IDprof;
	fecha FechaATENCION;
	char DetalleAtencion[60],apeynom[50],DNIcliente[50];
}Turn;
struct Atenciones{
	int IDprof;
	int cant_atenciones;
}Aten;
void CargarProfesional(FILE *prof,Profesionales Prof);
main()
{
	FILE *prof;
	CargarProfesional(prof,Prof);
}
void CargarProfesional(FILE *prof,Profesionales Prof)
{	Profesionales user_aux;
	int b=0;
	int permisos,n,min=0,may=0,dig=0,bandera=0,espacio=0,conse=0,cons=0,puntos=0;
	char contra[60];
	
	//Validacion de usuario
	do{
	system("color 74");
	marco();
	gotoxy(48,4);
	printf("EL USUARIO DEBE TENER:");
	gotoxy(48,5);
	printf("1. Comenzar con una letra minuscula.");
	gotoxy(48,6);
	printf("2. Tener al menos 2 letras mayusculas.");
	gotoxy(48,7);
	printf("3. Tener como maximo 3 digitos.");
	gotoxy(48,10);
	printf ("Nombre de usuario: ");
	_flushall();
	gets(Prof.UsuarioP);
	//validar que no exista el mismo usuario
	
	prof=fopen("Profesionales.dat","rb");
	
	if(prof!=NULL)
	{
		fread(&user_aux,sizeof(Profesionales),1,prof);
		while(!feof(prof))
		{
			if(strcmp(Prof.UsuarioP,user_aux.UsuarioP)==0)
			{
				b=1;
			}
			fread(&user_aux,sizeof(Profesionales),1,prof);
		}
	}
	fclose(prof);
	
	if(b==1)
	{
		gotoxy(48,11);
		printf("El Usuario ingresado ya existe, por favor ingrese otro");

	}
	else{
	//Entre 6 y 10 caracteres 	
	prof=fopen("Profesionales.dat","a+b");
	if(strlen(Prof.UsuarioP)>=6 and strlen(Prof.UsuarioP)<=10)
	{
		//Primera letra en minuscula
		if (Prof.UsuarioP[0] <= 122 && Prof.UsuarioP[0]>= 97)
		{
			min++;
			//Tener dos letras mayusculas
			for (int i=0;i<Prof.UsuarioP[i];i++)
			{
				if (Prof.UsuarioP[i] <= 90 && Prof.UsuarioP[i]>= 65)
				{
					may++;
				}
				if (Prof.UsuarioP[i] >= 48 && Prof.UsuarioP[i]<= 57)
				{
					 dig++;
				}
			}
			if(may>=2)
				{
					if(dig<=3)
					{
						gotoxy(48,12);
						printf("Usuario valido");
						gotoxy(48,14);
						system("pause");
						bandera=1;
					}
					else
					{
						gotoxy(48,12);
						printf("El usuario no puede tener mas de 3 digitos");
						gotoxy(48,14);
						printf("Usuario invalido");
						gotoxy(48,16);
						system("pause");
					}
				}
			else
			{
				gotoxy(48,12);
				printf("No posee la cantidad minima de mayusculas deben ser al menos 2");
				gotoxy(48,14);
				printf("Usuario invalido\n");
				gotoxy(48,16);
				system("pause");
			}
		}
		else
		{
			gotoxy(48,12);
			printf("La primera letra del usuario debe ser minuscula.");
			gotoxy(48,14);
			printf("Usuario invalido\n");
			gotoxy(48,16);
			system("pause");
		}
	}
	else
	{
		gotoxy(48,12);
		printf("La cantidad de caracteres debe ser de 6 a 10");
		gotoxy(48,14);
		printf("Usuario invalido\n");
		gotoxy(48,16);
		system("pause");
	}
	system("cls");
	min=0,may=0,dig=0;
	}
}while(bandera!=1);
	//CONTRASEÑA	
	if(bandera==1){
		do{
			system("color 74");
			marco();
			gotoxy(45,4);
			printf("LA CONTRASENIA DEBE TENER: ");
			gotoxy(45,5);
			printf("1. Al menos una letra mayuscula, una letra minuscula y un numero.");
			gotoxy(45,6);
			printf("2. Solo caracteres alfanumericos.");
			gotoxy(45,7);
			printf("3. Debera tener entre 6 y 32 caracteres.");
			gotoxy(45,8);
			printf("4. No debe tener mas de 3 caracteres numericos consecutivos.");
			gotoxy(45,9);
			printf("5. No debe tener 2 letras alfabéticamente consecutivas.");
			gotoxy(45,11);
			printf("Ingrese la contrasenia: ");
			_flushall();
			gets(Prof.ContraseniaP);
			if(strlen(Prof.ContraseniaP)>=6 and strlen(Prof.ContraseniaP)<=32)
				{
					for(int i=0;i<=Prof.ContraseniaP[i];i++)
					{
						if((Prof.ContraseniaP[i]>=40 and Prof.ContraseniaP[i]<=47) or (Prof.ContraseniaP[i]>=58 and Prof.ContraseniaP[i]<=63) or (Prof.ContraseniaP[i]>=90 and Prof.ContraseniaP[i]<=96) or (Prof.ContraseniaP[i]>=123 and Prof.ContraseniaP[i]<=126) or Prof.ContraseniaP[i]==239)
						{ 
							puntos++;
						}
						if(Prof.ContraseniaP[i]==32)
						{
							espacio++;
						}
						if(Prof.ContraseniaP[i]>=48 and Prof.ContraseniaP[i]<=57)
						{
							if(Prof.ContraseniaP[i]+1==Prof.ContraseniaP[i+1])
							{
								conse++;//numeros consecutivos
							}
						}
						if((Prof.ContraseniaP[i]>=65 and Prof.ContraseniaP[i]<=90) or (Prof.ContraseniaP[i]>=97 and Prof.ContraseniaP[i]<=122))
						{
							if(Prof.ContraseniaP[i]+1==Prof.ContraseniaP[i+1])
							{
								cons++;//Letras seguidas consecutivas
							}
						}
					}
					gotoxy(45,18);
					printf("puntos %d,espacios %d,numeros consecutivos %d,letras cons %d",puntos,espacio,conse,cons);
					if(puntos==0)
					{
						if(espacio==0)
						{
							if(conse<3)
							{
								if(cons<1)
								{
									gotoxy(45,13);
									printf("Contrasenia valida");
									gotoxy(45,15);
									system("pause");
									bandera=2;
								}
								else
								{
									gotoxy(48,13);
									printf("La contrasenia no puede tener dos letras seguidas consecutivas");
									gotoxy(45,15);
									system("pause");
								}
							}
							else
								{
								gotoxy(48,13);
								printf("La contrasenia no debe tener mas de 4 numeros consecutivos");
								gotoxy(45,15);
								system("pause");
								}
							}
						}
						else
						{
							gotoxy(48,13);
							printf("La contrasenia no debe tener espacios");
							gotoxy(45,15);
							system("pause");
						}
				}
				else
				{
			
					gotoxy(48,13);
					printf("La Contrasenia debe tener entre 6 y 32 caracteres");
					gotoxy(45,15);
					system("pause");
				}
				system("cls");
				puntos=0;
				espacio=0;
				conse=0;
				cons=0;
			}while(bandera!=2);
		}

 	//ingreso datos del usuario
	if(bandera==2)
	{
	system("color 74");
	marco();
	gotoxy(44,3);
	printf("USUARIO: %s",Prof.UsuarioP);
	srand(time(NULL));
	Prof.IDprof = 1+rand()%201;//le damos un id aleatorio , faltaria validacion de que no existe previamente.
	gotoxy(44,5);
	printf("Ingrese nombre y apellido: ");
	_flushall();
	gets(Prof.apeynom);
	gotoxy(44,6);
    printf("Ingrese el DNI: ");
	scanf("%d", &Prof.Dni);
	gotoxy(44,7);
	printf("Ingrese el telefono: ");
	_flushall();
	gets(Prof.Tel);
	gotoxy(44,8);
	printf("Permisos: admin= 1, Recepcionista= 2, Profecional= 3 : ");
	scanf("%d",&Prof.permisoP);
	fwrite(&Prof,sizeof(Profesionales),1,prof);
	}

	fclose(prof);
}
