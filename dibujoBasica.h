#include "membrete.h"

int calculadora ();
void botonesBasic ();

int calculadora (){	
		cuadritoLineaEfecto(3, 1, 41, 27);// marco calculadora
		cuadritoLineaEfecto(8,2,38,6); //falso display
		
		dibujarBotones(8, 7, 6, 3, 4, 2); // comienza en x=8, a la altura y=7, 6 de ancho y 3 de alto, 4 iguales deja 2 espacio
		dibujarBotones(8, 11, 6, 3, 3, 2);// 
		dibujarBotones(8, 15, 6, 3, 3, 2);
		dibujarBotones(8, 19, 6, 3, 3, 2);
		dibujarBotones(24, 23, 6, 3, 1, 2);
		
		cuadritoLineaEfecto(8,23,22,26); //boton cero
		cuadritoLineaEfecto(32,19,38,26); //boton =
		cuadritoLineaEfecto(32,11,38,18); //boton +
		
		return 0;
}

void botonesBasic (){
	//botones
		//1ra linea
		gotoxy(11,8); cout << "R";
		gotoxy(19,8); cout <<"/";
		gotoxy(27,8); cout << "*";
		gotoxy(35,8); cout << "-";
		
		//2da linea
		gotoxy(11,12); cout << "7";
		gotoxy(19,12); cout << "8";
		gotoxy(27,12); cout << "9";
		gotoxy(35,14); cout << "+";
		
		//3ra linea
		gotoxy(11,16); cout << "4";
		gotoxy(19,16); cout << "5";
		gotoxy(27,16); cout << "6";
		//gotoxy(35,18); cout << "+";
		
		//4ta linea
		gotoxy(11,20); cout << "1";
		gotoxy(19,20); cout << "2";
		gotoxy(27,20); cout << "3";
		gotoxy(35,22); cout << "=";
		
		//5ta linea
		gotoxy(15,24); cout << "0";
		gotoxy(27,24); cout << ".";
}

void instruccionBasica(){
	gotoxy(61,1); cout << "INSTRUCCIONES DE USO";
	gotoxy(47,4); cout << "Una vez ingresado el primer valor, presione";
	gotoxy(47,5); cout << "la tecla 'ENTER', esto le permitirá elegir";
	gotoxy(47,6); cout << "a continuación la operación a realizar. Aso-";
	gotoxy(47,7); cout << "ciándo simbolos con las cuatro operaciones";
	gotoxy(47,8); cout << "básicas (+,-,*,/); tras presionar 'ENTER'";
	gotoxy(47,9); cout << "podrá ingresar el segundo valor para operar.";
	gotoxy(47,10); cout << "Si presiona 'ENTER' se mostrará en pantalla";
	gotoxy(47,11); cout << "el resultado y la operación realizada ";
	gotoxy(47,12); cout << "(suponiendo que sea posible llevarla a cabo)";
	gotoxy(47,14); cout << "Admite el ingreso de números decimales en";
	gotoxy(47,15); cout << "todas las operaciones mencionadas.";
	gotoxy(47,17); cout << "PARA ACCEDER A LAS OPCIONES DEL MENÚ, INGRESE";
	gotoxy(47,18); cout << "LA LETRA CORRESPONDIENTE ANTES DE UNA OPERACIÓN";
	gotoxy(52, 21);cout <<BG_ORANGE "R"<<BG_COW << ". "<< BG_ORANGE <<"R" << BG_COW <<"ESETEAR ENTRADA DE DATOS";//
	gotoxy(52, 22);cout <<BG_ORANGE "P"<<BG_COW << ". REGRESAR AL MENÚ "<< BG_ORANGE <<"P"<< BG_COW <<"RINCIPAL";//
	gotoxy(52, 23);cout << BG_ORANGE <<"C"<<BG_COW << ". CAMBIAR A VERSION "<< BG_ORANGE << "C"<< BG_COW << "IENTIFICA";//
	gotoxy(52, 25);cout << BG_ORANGE <<"S"<<BG_COW << ". "<< BG_ORANGE <<"S"<< BG_COW <<"ALIR";
}
