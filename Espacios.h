#define TRUE 1
#define FALSE 0
struct fechA{
	int dia,mes,anio;
};
struct registro{
	char avance[380], doc[60];
	fecha fec;
	fechA fechAtencion;
	bool borrado;
	
}reg;
void progreso(registro reg,FILE *turn, FILE *client)
{
	int valoRDoc,datosPa, dias,meses,ed;
	char dniPac[50],valorDoc[50];
	int ani=2022;
	float pesoPac;
	system("color 71");
	marco();
	gotoxy(46,4);
	printf("Ingrese la fecha(2022)");
	gotoxy(46,5);
	printf("Dia: ");
	scanf("%d",&reg.fec.dia);
	gotoxy(46,6);
	printf("Mes: ");
	scanf("%d",&reg.fec.mes);
	gotoxy(46,7);
	printf("Ingrese el nombre del doctor: ");
	_flushall();
	gets(reg.doc);
	gotoxy(46,8);
	printf("BUSCAR PACIENTE: ");
	gotoxy(46,9);
	printf("DNI: ");
	_flushall();
	gets(dniPac);
	turn= fopen ("Turnos.dat","w+b");
	fread(&Turn,sizeof(Turnos),1,turn);
	while(!feof(turn)){
		if(strcmp(dniPac,Turn.DNIcliente)==0){
			client=fopen ("Clientes.dat","w+b");
			fread(&Clien,sizeof(Cliente),1,client);
				while(!feof(client)){
					datosPa=strcmp(Turn.DNIcliente,Clien.Dni);
					if(datosPa==0){
						gotoxy(46,10);
						printf("DATOS DEL PACIENTE");
						gotoxy(46,11);
						printf("Nombre: ");
						puts(Clien.apeynom);
						gotoxy(46,12);
						printf("DNI: %d",Clien.Dni);
						gotoxy(46,13);
						printf("Domicilio: ");
						gotoxy(46,14);
						puts(Clien.Domicilio);
						printf("Localidad: ");
						gotoxy(46,15);
						puts(Clien.Localidad);
						gotoxy(46,16);
						printf("Peso: %.1f",Clien.peso);
						gotoxy(46,17);
						printf("Telefono: ");
						puts(Clien.Telefono);
						//calcular edad
							if(reg.fec.dia<Clien.fechadeNacimiento.dia){
								reg.fec.dia=reg.fec.dia+30;
								reg.fec.mes=reg.fec.mes-1;
								dias=reg.fec.dia-Clien.fechadeNacimiento.dia;
							}else{
								dias=reg.fec.dia-Clien.fechadeNacimiento.dia;
							}
							if(reg.fec.mes<Clien.fechadeNacimiento.mes){
								reg.fec.mes=reg.fec.mes+12;
								ani=ani-1;
								meses=reg.fec.mes-Clien.fechadeNacimiento.mes;
							}else{
								meses=reg.fec.mes-Clien.fechadeNacimiento.mes;
							}
						ed=ani-Clien.fechadeNacimiento.anio;
						gotoxy(46,18);
						printf("Edad: %d",ed);
						
					}
				}	
			gotoxy(46,19);
			printf("Registre los avances del paciente:\n\t");
			_flushall();
			gets(reg.avance);
			
		}
		else
		{
			gotoxy(46,10);
			printf("PACIENTE NO REGISTRADO");
			system("pause");
		}
		fread(&reg, sizeof(registro),1,turn);
	}
}
void ListadeEspera(FILE *turn, Turnos Turn)
{
	system("color 71");
	marco();
		turn=fopen( "Profesionales.dat" , "rb" );
		fread(&Turn,sizeof(Turnos),1,turn);
		gotoxy(46,4);
		printf("Ingrese la fecha(2022)");
		gotoxy(46,5);
		printf("Dia: ");
		scanf("%d",&reg.fec.dia);
		gotoxy(46,6);
		printf("Mes: ");
		scanf("%d",&reg.fec.mes);
		gotoxy(46,7);
		printf("Lista de espera:");
		int verDia, verMes,e=1;;
		while(!feof(turn)){
					system("color 71");
					marco();
					reg.fec.dia=Turn.FechaATENCION.dia;
					reg.fec.dia=verDia;
					reg.fec.mes=Turn.FechaATENCION.mes;
					reg.fec.mes=verMes;
					if(verDia ==0 && verMes==0){
						while(!feof(turn)){
							gotoxy(46,8);
							printf("%d.-",e);
							puts(Turn.apeynom);//nombre
							e++;
							system("pause");
							gotoxy(46,8);
						}
					}else{
						gotoxy(46,8);
						printf("No hay turnos registrados para la fecha.");
					}
				fread(&Turn,sizeof(Turnos),1,turn);	
		}

}
void EvolucionTrat(FILE *prof, Profesionales Prof,registro reg,FILE *client,FILE *turn)
{
		system("color 71");
		prof=fopen( "Profesionales.dat" , "w+b" );
		fread(&Prof,sizeof(Profesionales),1,prof);
		progreso(reg,turn,client);
}
