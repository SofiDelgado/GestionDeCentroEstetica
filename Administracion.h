struct Recepcionista{
	int IDrecep,Dni,permisoR;
	char apeynom[60],Telefono[60];
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
	char apeynom[60], Domicilio[60],Localidad[60],Telefono[25];
	int Dni;
	float peso;
	fecha fechadeNacimiento;
};
struct Turnos{
	int IDprof,DNIcliente;
	fecha FechaATENCION;
	char DetalleAtencion[60];
	
};
void CargarRecepcionista(FILE *recep,Recepcionista Recep)
{
	arch = fopen ("Recepcionistas.dat ","a+b");
	printf("Ingrese el apellido y nombre: ");
    _flushall();
    gets(Recep.apeynom);
    printf("Ingrese el DNI: ");
    scanf("%d",&Recep.Dni);
    printf("Ingrese el telefono: ");
    _flushall();
    gets(Recep.Telefono); 
	  
	int permisos,n,min=0,may=0,dig=0;
	char contra[60];
			printf("\nEL USUARIO DEBE: \n1. Comenzar con una letra minuscula.\n2. Tener al menos 2 letras mayusculas.\n3. Tener como maximo 3 digitos.\n");
			do{	
			printf ("\nNombre de usuario: ");
			_flushall();
			gets(Recep.UsuarioR);
			n=strlen(Recep.UsuarioR);
			//Primera letra en minuscula
			if (Recep.UsuarioR[0] <= 122 && Recep.UsuarioR[0]>= 97) min++;
			//Tener dos letras mayusculas
			for (int i=0;i<n;i++)
			{
			if (Recep.UsuarioR[i] <= 90 && Recep.UsuarioR[i]>= 65) may++;
			}
			//tener maximo 3 digitos
			for (int i=0;i<n;i++)
			{
		        if ( (Recep.UsuarioR[i] >= 33) && (Recep.UsuarioR[i]<= 47) || (Recep.UsuarioR[i] >= 58) && (Recep.UsuarioR[i]<= 64)|| (Recep.UsuarioR[i] >= 166) && (Recep.UsuarioR[i]<= 175)) dig++;
		    }
		    if(n<6 or n>10 or min==0 or may<2 or dig>3)
				{
					printf("\nEL USUARIO DEBE: \n1. Comenzar con una letra minuscula.\n2. Tener al menos 2 letras mayusculas.\n3. Tener como maximo 3 digitos.\n");
				}
			//CORRECTO 
			if(n>=6 and n<=10 and min==1 and may>=2)
			{
	
				printf("CORRECTO!");
			}
		}while(n<6 or n>10 or min==0 or may<2 or dig>3);

			printf ("\nContrasenia: ");
			_flushall();
			gets(contra);
			printf("Permisos: \n Administrador 1 \nRecepcionista 2\Profecional medico 3: ");
			scanf("%d",&Recep.permisoR);;
	    fwrite(&Recep,sizeof(Recepcionista),1,arch);
		fclose(arch);
}
void CargarProfesional(FILE *prof,Profesionales Prof)
{
	arch = fopen ("Profesionales.dat","a+b");
	printf("Ingrese nombre y apellido: ");
   	_flushall();
    gets(Prof.apeynom);
    printf("Ingrese el DNI: ");
    scanf("%d", &Prof.Dni);
    printf("Ingrese el telefono: ");
    _flushall();
    gets(Prof.Tel);
	//Validacion de usuario
	int permisos,n,min=0,may=0,dig=0;
	char contra[60];
			printf("\nEL USUARIO DEBE: \n1. Comenzar con una letra minuscula.\n2. Tener al menos 2 letras mayusculas.\n3. Tener como maximo 3 digitos.\n");
			do{	
			printf ("\nNombre de usuario: ");
			_flushall();
			gets(Prof.UsuarioP);
			n=strlen(Prof.UsuarioP);
			//Primera letra en minuscula
			if (Prof.UsuarioP[0] <= 122 && Prof.UsuarioP[0]>= 97) min++;
			//Tener dos letras mayusculas
			for (int i=0;i<n;i++)
			{
			if (Prof.UsuarioP[i] <= 90 && Prof.UsuarioP[i]>= 65) may++;
			}
			//tener maximo 3 digitos
			for (int i=0;i<n;i++)
			{
		        if ( (Prof.UsuarioP[i] >= 33) && (Prof.UsuarioP[i]<= 47) || (Prof.UsuarioP[i] >= 58) && (Prof.UsuarioP[i]<= 64)|| (Prof.UsuarioP[i] >= 166) && (Prof.UsuarioP[i]<= 175)) dig++;
		    }
		    if(n<6 or n>10 or min==0 or may<2 or dig>3)
				{
					printf("\nEL USUARIO DEBE: \n1. Comenzar con una letra minuscula.\n2. Tener al menos 2 letras mayusculas.\n3. Tener como maximo 3 digitos.\n");
				}
			//CORRECTO 
			if(n>=6 and n<=10 and min==1 and may>=2)
			{
				contarusuarioR++;
				printf("CORRECTO!");
			}
		}while(n<6 or n>10 or min==0 or may<2 or dig>3);

			
			printf ("\nContrasenia: ");
			_flushall();
			gets(contra);
			printf("Permisos: \n Administrador 1 \n Recepcionista 2\n Profecional medico 3 \opcion: ");
			scanf("%d",&Prof.permisoP);
	
	//termina validacion de usuario
	fwrite(&Prof,sizeof(Profesionales),1,arch);
	fclose(arch);
	
}
void ver(FILE *prof,Profesionales Prof)
{
	printf("VER");
	arch = fopen ("Profesionales.dat","a+b");
	fread(&Prof,sizeof(Profesionales),1,arch);

		while(!feof(arch))
		{
		printf("\nNombre y apellido: %s", Prof.apeynom);
		printf("\nDNI: %d", Prof.Dni);
		printf("\nTelefono: %s", Prof.Tel);
		printf("\nUsuario: %s",Prof.UsuarioP);
		fread(&Prof,sizeof(Profesionales),1,arch);
		}

	fclose(arch);
}
