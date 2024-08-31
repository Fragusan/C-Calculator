void membrete (){
	system("cls");
	system("mode con: cols=100 lines=30");
	system("color 70");
	sinMaximVentana();
	margen();
}

void inicio (){
	membrete ();
	logoText();
	hiddenCur();
	logoIcon();
	parpadeo("PRESIONA ENTER PARA INICIAR", 24, 'e');
}
