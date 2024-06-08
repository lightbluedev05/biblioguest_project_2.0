#include "functions.h"
#include <windows.h>
#include <iostream>


void gotoxy(int x, int y){
	COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hide_cursor(){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // Oculta el cursor
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void show_cursor(){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = true; // Oculta el cursor
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void change_color(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void rectangle(int ancho, int alto, int x, int y){
	gotoxy(x, y);
	std::cout<<"+";
	for(int i=0; i<ancho-2; i++){
		std::cout<<"-";
	}
	std::cout<<"+"<<std::endl;
	
	for(int j=0; j<alto; j++){
		gotoxy(x, y+j+1);
		std::cout<<"|";
		for(int k=0; k<(ancho-2); k++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
	}
	
	gotoxy(x, y+alto+1);
	std::cout<<"+";
	for(int i=0; i<ancho-2; i++){
		std::cout<<"-";
	}
	std::cout<<"+";
}

void button(int ancho, int alto, int x, int y, std::string texto){
	rectangle(ancho, alto, x, y);
	
	gotoxy(x+((ancho-texto.size())/2), y+(alto+1)/2);
	std::cout<<texto;
}