#include "colors.h"
#include "basicFunctions.h"
#include "dibujoBasica.h"
#include "logo.h"
#include "splash.h"
#include <algorithm> // usando all_of(); descartado por regex
#include <conio.h>
#include <string>
#include <regex> 
#include <cctype>  // para toupper()
#include <iostream>

using namespace std;

bool esNumero (string ingreso);

void basicVersion ();

bool esDecimal(const string& input) {//verifica si es numerico y/o decimal 
    regex pattern("^[0-9]+(\\.[0-9]+)?$");
    return regex_match(input, pattern);
}

void errorMsj (string txt){
	alternarLocale();
	cuadritoLineaEfecto(18,14,52,16);
	alternarLocale();
	hiddenCur();
	gotoxy(19,15); cout << WINE << txt << BLACK;
	alternarLocale();
	Sleep(2000);
	system("cls");
}

void errorMsj (string txt, int xi, int yi, int xf, int yf){
	alternarLocale();
	cuadritoLineaEfecto(xi, yi,xf,yf);
	alternarLocale();
	hiddenCur();
	gotoxy(19,15); cout << WINE << txt << BLACK;
	alternarLocale();
}


/*int main (){

	int opc;
	
	do{
		system("mode con: cols=100 lines=30");
		system("color 70");
		sinMaximVentana();
		margen();
		textoCentro("MENU PRINCIPAL",5);
		textoCentro("*********************",6);
		alternarLocale();
		hiddenCur();
		textoCentro("Usa el teclado númerico para seleccionar una de las opciones", 8);
		gotoxy(20, 10);printf("1. INGRESAR EN VERSION BASICA");//en menu 1 y 2 deberia tambien dejarme modificar el nivel de dificultad
		gotoxy(20, 11);printf("2. INGRESAR EN VERSION CIENTIFICA");//
		gotoxy(20, 12);printf("0. SALIR");
		gotoxy(20, 15);printf("OPCIÓN SELECCIONADA: -> ");
		showCur();
		alternarLocale();
		//scanf("%i", &opc);
		cin >> opc;
	}while (opc<0 || opc > 2);

	switch(opc){
		case 0:
			//salida(); //GENERA UN MENIUU DE SALIDA
			break;
		case 1:
			//GENERAR UNA VERSION BASICA
			basicVersion();
		case 2:
			//gENERAR VERSION CIENTIFICA
			break;
		default :
			cout << WINE;
			alternarLocale();
			textoCentro("OPCION INGRESADA NO VÁLIDA", 7);
			cout << BLACK;
			Sleep(600);
			//menuPrincipal();
			break;
	}

	//
	
	//gotoxy(50, 15); MITAD DE TODO
	
}
*/
//basicVersion
int main (){
	inicio();
	charger("INICIANDO MOTOR NÚMERICO");
    membrete ();
	double aux=0;
	
	while(true){
		membrete ();
		gotoxy(9,4); cout << "                           ";
		gotoxy(9,5); cout << "                           ";
		string opc;
		char operacion='\0';
		double num1 = 0, num2 = 0;
		char tecla;
		double resultado=0;
		char salir='\0';
		
		calculadora();
		//lineaH (7, 40, 10, 178);
		//lineaV (5,15, 7, 177);
		alternarLocale();
		botonesBasic();
		instruccionBasica();
		
		gotoxy(12,3);
		aux == 0 ? cout << "INGRESE EL PRIMER NÚMERO  ": cout << "TRABAJANDO CON RESULTADO ANTERIOR" ;
		showCur();
		gotoxy(9,5);
		
		cin >> opc;
		//if (all_of(opc.begin(), opc.end(), ::isdigit)) {  esNumero(opc) &&	
			if (esDecimal(opc)) {
			//revisar lo del punto
			num1=stod(opc);
			gotoxy(9,4); cout << BLUE << opc << BLACK;
			
			//detectyar operacion
			
				tecla= _getch();
				toupper(tecla);
				
				if(!(esDecimal(string(1, tecla)))){
					//swicth case
					switch(tecla)
							{
							case '+': 
								operacion='+';
								gotoxy(9,4); cout << BLUE << opc << GREEN <<  " + "  << BLACK;
							break;
							case '-': 
								operacion='-';
								gotoxy(9,4); cout << BLUE << opc << GREEN << " -"  << BLACK;
							break;
							case '*': 
								operacion='*';
								gotoxy(9,4); cout << BLUE << opc << GREEN << " *"  << BLACK;
							break;
							case '/':
								operacion='/';
								gotoxy(9,4); cout << BLUE << opc << GREEN << " /"  << BLACK;
							break;
							default: 
							errorMsj("INGRESO UNA OPERACIÓN INVÁLIDA");
							continue;
							}
				}
			
			gotoxy(12,3); cout << "INGRESE EL SEGUNDO NÚMERO";
			cin.clear();
			gotoxy(9,5); cout << "                           ";
			gotoxy(9,5);
			cin >> opc;
			
			if (esDecimal(opc)) {
			//revisar lo del punto
			num2=stod(opc);//transforma el string a double
			
			gotoxy(9,4); cout << BLUE << num1 << GREEN << " " << operacion << " " << BLUE<< opc  << BLACK;
			cin.clear();
			gotoxy(9,5); cout << "                           ";
			
			switch(operacion)
			{
				case '+':
					resultado=sumar(num1, num2);
					gotoxy(9,5);cout << MAGENTA << resultado << BLACK;
					Sleep(3500);
					break;
				case '-':
					resultado=resta(num1, num2);
					gotoxy(9,5);cout << MAGENTA << resultado << BLACK;
					Sleep(3500);
					break;
				case '*':
					resultado=producto(num1, num2);
					gotoxy(9,5);cout << MAGENTA << resultado << BLACK;
					Sleep(3500);
					break;
				case '/':
					if(num2==0){
					errorMsj("NO ES POSBILE DIVIDIR POR 0");
					Sleep(2500);
					alternarLocale();
					break;
					}
					resultado=division(num1, num2);
					gotoxy(9,5);cout << MAGENTA << resultado << BLACK;
					Sleep(3500);
					break;
				default:
					errorMsj("OPERACIÓN INGRESADA INVÁLIDA");
					system("cls");
					continue;
			}
			
			
			alternarLocale();
		}
		}else if (opc.size() == 1 && isalpha(opc[0])){ //si la opcion ingresada es una letra
				char option = toupper(opc[0]);
				switch (option){
					case 'T':
					//winner(id);//algo
					cout << "La t si anda";
					alternarLocale();
					Sleep(1500);
					break;
				case 'L':
					//looser(id);
					break;
				case 'B':
					alternarLocale();
					break;
				case 'S':
					//(18,14,52,16);
					corregoirImg();
					errorMsj("\t¿ESTÁ SEGURO QUE DESEA SALIR DEL PROGRAMA?", 18,14,66,18);
					alternarLocale();
					gotoxy(19,16); cout<< WINE << "(\aS para confirmar | N para cerrar está ventana)" << BLACK;
					showCur();
					gotoxy(46,17);
					cin >> salir;
					if(toupper(salir) == 'S'){
					exit(0);}
					alternarLocale();
					break;
				default:
					errorMsj("LA LETRA INGRESADA NO  ES  VÁLIDA\t");
					system("cls");
					
					break;
				}
			}else{
			errorMsj("LA OPCIÓN INGRESADA NO ES VÁLIDA");
			}
		
	}
return 0;
}
