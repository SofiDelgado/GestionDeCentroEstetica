void login(FILE *prof, FILE *recep,Profesionales Prof,Recepcionista Recep,int &permiso,bool &verificacion)
{	

	int i,b;
		int mcontra=0, musuario=0;
	int d;
	char usuario[60],contrasenia[60];
	  gotoxy(52,6);
	printf("INICIO DE SESION");
		gotoxy(50,11);
		printf("USUARIO:");
		_flushall();
		gets(usuario);
	gotoxy(50,12);
		printf("Contrasenia:");
		_flushall();
		gets(contrasenia);
		
		prof = fopen ("Profesionales.dat","rb");
		
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
		
		recep = fopen ("Recepcionistas.dat","rb");
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
			gotoxy(45,13);
			printf("Los datos ingresados son incorrectos");
		}
		else
		{
			gotoxy(45,13);
			verificacion=true;
			printf("Inicio de sesion correcto.");
		}

}
