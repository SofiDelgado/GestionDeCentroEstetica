void login(FILE *prof, FILE *recep,Profesionales Prof,Recepcionista Recep,int &permiso,bool &verificacion)
{	
	marco();
	int i,b;
	int mcontra=0, musuario=0;
	int d;
	char usuario[60],contrasenia[60];
	gotoxy(50,5);
	printf("==================");
	gotoxy(50,6);
	printf("INICIO DE SESION");
	gotoxy(50,7);
	printf("==================");
	gotoxy(49,10);
	printf("USUARIO:");
	_flushall();
	gets(usuario);
	gotoxy(49,11);
	printf("Contrasenia:");
	_flushall();
	gets(contrasenia);
		
	prof = fopen ("Profesional.dat","rb");
	recep = fopen ("Recepcionistas.dat","rb");
	if(prof==NULL or recep==NULL)
	{
	system("cls");
	marco();
	gotoxy(15,5);
	printf("El archivo 'Profesional.dat' o 'Recepcionistas.dat' no fue creado o se elimino, contacte con soporte.");
	gotoxy(30,8);
	system("pause");
	}

		fread(&Prof,sizeof(Profesionales),1,prof);
		while(!feof(prof) and mcontra==0 and musuario==0)
		{
			if((strcmp(usuario,Prof.UsuarioP)!=0) or (strcmp(contrasenia,Prof.ContraseniaP)!=0)) //Cambio a uso de función strcmp()
			{
				fread(&Prof,sizeof(Profesionales),1,prof);
			}
			else
			{
				mcontra=1;
				musuario=1;
				permiso=Prof.permisoP;
			}
		}
		fclose(prof);

		fread(&Recep,sizeof(Recepcionista),1,recep);
		while(!feof(recep) and mcontra==0 and musuario==0)
		{
			if((strcmp(usuario,Recep.UsuarioR)!=0) or (strcmp(contrasenia,Recep.ContraseniaR)!=0)) //Cambio a uso de función strcmp()
			{
				fread(&Recep,sizeof(Recepcionista),1,recep);
			}
			else
			{
				mcontra=1;
				musuario=1;
				permiso=Recep.permisoR;
			}
		}
		
		
		fclose(recep);
		
		if(mcontra==0 or musuario==0)
		{
			gotoxy(49,13);
			printf("Los datos ingresados son incorrectos");
		}
		else
		{
			gotoxy(49,13);
			verificacion=true;
			printf("Inicio de sesion correcto.");
			gotoxy(49,15);
			system("pause");
		}

}
