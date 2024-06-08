// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>


void gotoxy(int x, int y);

void hide_cursor();

void show_cursor();

void change_color(int color);

void rectangle(int ancho, int alto, int x, int y);

void button(int ancho, int alto, int x, int y, std::string texto);

#endif // FUNCTIONS_H
