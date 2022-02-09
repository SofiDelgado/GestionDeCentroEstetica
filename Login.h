void login(FILE *prof,Profesionales Prof,Recepcionista Recep)
{	

	int i,b;
		int mcontra=0, musuario=0;
	
	char usuario[60],contrasenia[60];
		printf("------------------------");
		printf("\nINICIO DE SESION\n");
		printf("\nUSUARIO:");
		_flushall();
		gets(usuario);
		printf("\nContrasenia:");
		_flushall();
		gets(contrasenia);
		
		prof = fopen ("Profesionales.dat","a+b");
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
			}
		}
		if(mcontra==0 or musuario==0)
		{
			printf("\nLos datos ingresados son incorrectos");
		}
		else
		{
			printf("\nInicio de sesion correcto.\n");
			//verificacion=true;
		}
		
		fclose(prof);

}
