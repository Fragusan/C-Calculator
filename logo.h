
void logoText(){
	gotoxy(13, 2); printf(".d88b    db    8    .d88b 8    8 8       db    888b. .d88b. 888b.    db\n");
    gotoxy(13, 3); printf("8P      dPYb   8    8P    8    8 8      dPYb   8   8 8P  Y8 8  .8   dPYb\n");
    gotoxy(13, 4); printf("8b     dPwwYb  8    8b    8b..d8 8     dPwwYb  8   8 8b  d8 8wwK'  dPwwYb\n");
    gotoxy(13, 5); printf("`Y88P dP    Yb 8888 `Y88P `Y88P' 8888 dP    Yb 888P' `Y88P' 8  Yb dP    Yb\n");
}

void logoIcon(){
		cuadritoLineaEfecto(38, 7, 64, 21);// marco calculadora
		cuadritoLineaEfecto(40,8,62,11); //falso display
		
		dibujarBotones(40, 12, 4, 2, 4, 2); // comienza en x=8, a la altura y=7, 6 de ancho y 3 de alto, 4 iguales deja 2 espacio
		dibujarBotones(40, 15, 4, 2, 3, 2);// 
		dibujarBotones(40, 18, 4, 2, 3, 2);
		cuadritoLineaEfecto(58,15,62,20); //boton +
}
