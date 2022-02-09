void login(FILE *arch,Profesionales Prof,Recepcionista Recep)
{	

	int i,b;
	arch = fopen ("Profesionales.dat","a+b");
	char usuario[60],contrasenia[60];
		printf("------------------------");
		printf("\nINICIO DE SESION\n");
		printf("\nUSUARIO:");
		_flushall();
		gets(usuario);
		printf("\nContrasenia:");
		_flushall();
		gets(contrasenia);
		
		fread(&Prof,sizeof(Profesionales),1,arch);
		
		while (!feof(arch))
		{
			if (strcmp(usuario, Prof.UsuarioP)==0 and strcmp(contrasenia, Prof.ContraseniaP)==0)
			{
			b=1;
			}
		}
		fclose(arch);
		    if (b==1)
			{
				printf("Correcto!");
			}else printf("Datos no encontrados...");
		printf("------------------------");
}
