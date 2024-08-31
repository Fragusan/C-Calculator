#include "colors.h" //libreria de github para colorear fondos y textos
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

//Prototipos
void sinMaximVentana(); // no funciona, la idea es que no se pueda modificar el tamaño de la ventana
void alternarLocale(); //habilita y desabilita entre las opciones de escritura español y los caracteres ascii extendidos
void gotoxy(int, int); //para colocar texto y menus en pcoordenadas de pantalla
void lineaH (int xi, int xf, int y, int caracter);
void lineaV (int yi, int yf, int x, int caracter);
void dibujarBotones(int inicioX, int inicioY, int ancho, int alto, int cantidad, int espacio);
void cuadrito(int, int, int, int); // genera rectangulos decorativos con lineas dobles en patalla
void cuadrito(int xs, int ys, int xe, int ye, int esquina1, int esquina2, int esquina3, int esquina4);
void cuadritoLineaSola(int xs, int ys, int xe, int ye);//genera retangulos decorativos con linea  simple y efecto relieve
void cuadritoLineaEfecto(int xs, int ys, int xe, int ye);
void margen(); //usa el anterior con valores seteados para pantalla
void textoCentro (char *, int); // centra texto en la altura de coordenas de y que se le indique
void titulo(); // mentiene la cabecera del juego aún luego de borrar la pantalla de la consola
void charger(string txt); // barra de carga de adorno
void hiddenCur(); // esconde el cursosr
void showCur(); // muestra el cursor 




void sinMaximVentana(){//funciona en windows con permisos elevados
	HWND consoleWindow; 
	consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE,GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

}

void alternarLocale() {
    // Obtener la configuración regional actual
    const char* localeActual = setlocale(LC_CTYPE, NULL);

    // Verificar la configuración regional actual y alternar
    if (localeActual && strcmp(localeActual, "Spanish_Spain.1252") == 0) {
        setlocale(LC_CTYPE, "C");
    } else {
        setlocale(LC_CTYPE, "Spanish_Spain.1252");
    }
}

void gotoxy(int x, int y){
	HANDLE hcon;
	hcon= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void cuadrito(int xs, int ys, int xe, int ye){ // genera marcos decorativos
	int i;
	//control horizontal
	for (i= xs; i<= xe; i++){
		gotoxy(i,ys); printf("%c\n", 205);
		gotoxy(i,ye); printf("%c\n", 205);
	}
	//control vertical
	for (i= ys; i<= ye; i++){
		gotoxy(xs,i); printf("%c\n", 186);
		gotoxy(xe,i); printf("%c\n", 186);
	}
	//primera esquina
	gotoxy(xs,ys); printf("%c\n", 201);
	//segunda esquina
	gotoxy(xe,ys); printf("%c\n", 187);
	//tercera esquina
	gotoxy(xe,ye); printf("%c\n", 188);
	//cuarta esquina
	gotoxy(xs,ye); printf("%c\n", 200);
}

void cuadrito(int xs, int ys, int xe, int ye, int esquina1, int esquina2, int esquina3, int esquina4){ //hacer sobrecarga de metodo para cuadro anidado
	int i;
	//control horizontal
	for (i= xs; i<= xe; i++){
		gotoxy(i,ys); printf("%c\n", 205);
		gotoxy(i,ye); printf("%c\n", 205);
	}
	//control vertical
	for (i= ys; i<= ye; i++){
		gotoxy(xs,i); printf("%c\n", 186);
		gotoxy(xe,i); printf("%c\n", 186);
	}
	//primera esquina
	gotoxy(xs,ys); printf("%c\n", esquina1);
	//segunda esquina
	gotoxy(xe,ys); printf("%c\n", esquina2);
	//tercera esquina
	gotoxy(xe,ye); printf("%c\n", esquina3);
	//cuarta esquina
	gotoxy(xs,ye); printf("%c\n", esquina4);
}

void cuadritoLineaEfecto(int xs, int ys, int xe, int ye){ // genera marcos decorativos con relieve simulado
	int i;
	//control horizontal
	for (i= xs; i<= xe; i++){
		gotoxy(i,ys); printf("%c", 196);
		gotoxy(i,ye); printf("%c", 205);
	}
	//control vertical
	for (i= ys; i<= ye; i++){
		gotoxy(xs,i); printf("%c", 179);
		gotoxy(xe,i); printf("%c", 186);
	}
	//primera esquina
	gotoxy(xs,ys); printf("%c", 218);
	//segunda esquina
	gotoxy(xe,ys); printf("%c", 191);
	//tercera esquina
	gotoxy(xe,ye); printf("%c", 188);
	//cuarta esquina
	gotoxy(xs,ye); printf("%c", 192);
}

void cuadritoLineaSola(int xs, int ys, int xe, int ye){ // genera marcos decorativos con relieve simulado
	int i;
	//control horizontal
	for (i= xs; i<= xe; i++){
		gotoxy(i,ys); printf("%c", 196);
		gotoxy(i,ye); printf("%c", 196);
	}
	//control vertical
	for (i= ys; i<= ye; i++){
		gotoxy(xs,i); printf("%c", 179);
		gotoxy(xe,i); printf("%c", 179);
	}
	//primera esquina
	gotoxy(xs,ys); printf("%c", 218);
	//segunda esquina
	gotoxy(xe,ys); printf("%c", 191);
	//tercera esquina
	gotoxy(xe,ye); printf("%c", 217);
	//cuarta esquina
	gotoxy(xs,ye); printf("%c", 192);
}

void lineaH (int xi, int xf, int y, int caracter){
	int i;
	for (i= xi; i<= xf; i++){
		gotoxy(i,y); printf("%c\n", caracter);
	}
}

void lineaV (int yi, int yf, int x, int caracter){
	int i;
	for (i= yi; i<= yf; i++){
		gotoxy(x,i); printf("%c\n", caracter);
	}
}

void dibujarBotones(int inicioX, int inicioY, int ancho, int alto, int cantidad, int espacio){
    for (int i = 0; i < cantidad; i++){
        int xs = inicioX + i * (ancho + espacio);
        int xe = xs + ancho;
        cuadritoLineaEfecto(xs, inicioY, xe, inicioY + alto);
    }
}

void margen(){
	cuadrito(1,0,98,28); // recuadro de pantalla
}

void textoCentro (char *texto, int y){//centra el texto en pantalla a la altura de y que se le indique (usa gotoxy())
	int longitud = strlen(texto);
	gotoxy(50-(longitud/2), y); printf(texto);
}

void charger(string txt){
	int i;
	char* charArray = new char[txt.length() + 1]; // +1 para el carácter nulo
    strcpy(charArray, txt.c_str());
    
	alternarLocale();
	textoCentro(charArray, 24);
	alternarLocale();
	for(i=4; i<= 95; i++){
		gotoxy(i, 26); printf("%c\n", 176);
	}
	
	for(i=4; i<= 95; i++){
		cout << ORANGE;
	gotoxy(i, 26); printf("%c\n", 178);
	Sleep(12);//retardo para apariencia de carga
	}
	cout << BLACK;
}

void hiddenCur(){
	printf("\e[?25l");
}

//muestra el cursor
void showCur(){
	printf("\e[?25h");
}

void parpadeo(const char* txt, int y, char modo) {
    bool show = true;
    int longitud = strlen(txt);
    char* espacio = new char[longitud + 1]; // +1 para el carácter nulo
    // Rellena el array con espacios y añade el carácter nulo al final
	memset(espacio, ' ', longitud);
    espacio[longitud] = '\0';

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if ((modo == 'e' && ch == 13) || // Enter
                (modo == 'a') || // Cualquier tecla
                (modo == 'n' && ch >= '0' && ch <= '9')) { // Tecla numérica
                textoCentro(espacio, y);
                break;
            }
        }
        if (show) {
            textoCentro(const_cast<char*>(txt), y);
        } else {
            textoCentro(espacio, y);
        }
        show = !show;

        Sleep(500); // retardo
        gotoxy(0, y);
    }
    delete[] espacio; // Libera la memoria
}

void corregoirImg(){
	gotoxy(18,15); cout << "\033[K";
	gotoxy(18,16); cout << "\033[K";
	gotoxy(18,17); cout << "\033[K";
	alternarLocale();
	gotoxy(98,15); printf("%c", 186);
	gotoxy(98,16); printf("%c", 186);
	gotoxy(98,17); printf("%c", 186);
	alternarLocale();
}
