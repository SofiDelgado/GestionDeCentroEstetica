void marco()
{//marco
		for (int j=1; j < 120; j++) {
	  	gotoxy(j, 1);
	  	printf("%c", 177);
	  	gotoxy(j, 24);
	 	 printf("%c",177);
	 	}
		for(int d = 2; d < 24; d++) {
		gotoxy(1, d);
		printf("%c", 179);
		gotoxy(119, d);
		printf("%c", 179);
		}
		gotoxy(1, 1);
		printf("%c", 223);

		gotoxy(119, 1);
		printf("%c",223);
		
		gotoxy(1, 24);
		printf("%c", 223);
		
		gotoxy(119, 24);
		printf("%c", 223);
		//Fin Marco
}
