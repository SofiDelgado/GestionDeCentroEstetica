void gotoxi(int x,int y)
{
	HANDLE Manipulador;
	COOR Coordenadas;
	Manipulador = GetStdHandle(STD_PUTPUT_HANDLE);
	Coordenadas.X=x;
	Coordenadas.Y=y;
	SetConsoleCursorPosition(Manipulador,Coordenadas);
}
