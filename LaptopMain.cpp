#include "LaptopMain.h"
#include "GestorVentanas.h"
#include "functions.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void LaptopMain::mostrar() {
  change_color(112);
  system("cls");

  change_color(240);
  rectangle(46, 19, 37, 3);

  change_color(244);
  gotoxy(53,4);
  cout<<"MENU DE LAPTOPS";

  change_color(240);
  gotoxy(38, 5);
  cout<<"--------------------------------------------";
  gotoxy(48, 7);
  cout<<"Escoja que desea realizar:";

  change_color(241);
  gotoxy(40, 20);
  cout<<"UTILIZE LAS FLECHAS PARA SELECCIONAR LAS";
  gotoxy(48, 21);
  cout<<"OPCIONES (ARRIBA Y ABAJO)";
}

void dibujar_laptops(vector<vector<string>> data, int i, int coord){
  int size=i+7;
  for(i; i<size; i++){
    change_color(241);
    button(10, 1, 26+(coord*11), 7, data[i][0]);

    for(int j=0; j<6; j++){
      string aux="";
      if(data[i][j+1]=="1"){
        aux="No";
        change_color(244);
      } else {
        aux="Si";
        change_color(242);
      }

      button(10, 1, 26+(coord*11), 10+(j*3), aux);
    }
    coord++;
  }
}

void LaptopMain::listar_laptops() {
  //*----------CONSEGUIR DATA DE LAPTOPS-------------
  //$ HORARIOS_DATA.CSV
  ifstream file("horarios_data.csv");
  string linea;

  vector<vector<string>> data;

  while(getline(file, linea)){
    vector<string> horarios={};
    string horario="";
    stringstream ss(linea);

    while(getline(ss, horario, ',')){
      horarios.push_back(horario);
    }
    data.push_back(horarios);
  }
  file.close();

  //*----------IMPRIMIR DATA DE LAPTOPS-------------
  change_color(112);
  system("cls");

  change_color(240);
  rectangle(94, 26, 10, 1);
  gotoxy(13, 2);
  cout<<"Verifica que cubiculos";
  gotoxy(13, 3);
  cout<<"estan disponibles...";

  change_color(241);
  gotoxy(50, 3);
  cout<<"LISTA DE LAPTOPS";

  button(13, 1, 12, 10, "08AM-10AM");
  button(13, 1, 12, 13, "10AM-12PM");
  button(13, 1, 12, 16, "12PM-02PM");
  button(13, 1, 12, 19, "02PM-04PM");
  button(13, 1, 12, 22, "04PM-06PM");
  button(13, 1, 12, 25, "06PM-08PM");


  int tecla=72, opc=0;
  while(tecla!=13){
    //$ TECLA PRESIONADA
    if(tecla==75 && opc>0){
      opc--;
    } else if (tecla==77 && opc<2){
      opc++;
    }

    //$ EJECUCION DE OPCION
    change_color(240);
    gotoxy(27, 5);
    cout<<"*==========================================================*";
    change_color(31);
    switch(opc){
      //$ 1RA PARTE
      case 0:
        gotoxy(27, 5);
        cout<<"*===================";
        dibujar_laptops(data, 0, 0);
        break;

      //$ 2DA PARTE
      case 1:
        gotoxy(47, 5);
        cout<<"====================";
        dibujar_laptops(data, 7, 0);
        break;

      //$ 3RA PARTE
      case 2:
        gotoxy(67, 5);
        cout<<"===================*";
        dibujar_laptops(data, 14, 0);
        break;
    }

    tecla = _getch();
  }

  getch();
}

void LaptopMain::seleccionar_opcion(GestorVentanas& gestor) {
  int opc=1, tecla=72;
  while(tecla!=13){

    if(tecla==72 && opc>1){
      opc--;
    }
    if(tecla==80 && opc<3){
      opc++;
    }

    switch(opc){
      //$ LISTADO
			case 1: 
				change_color(241);
				gotoxy(48, 9);
        cout<<"+-----------------------+";
        gotoxy(46, 10);
        cout<<"->|     Listar Laptops    |";
        gotoxy(48, 11);
        cout<<"+-----------------------+";
        change_color(240);

        gotoxy(48, 12);
        cout<<"+-----------------------+";
        gotoxy(46, 13);
        cout<<"  |        Reservar       |";
				gotoxy(48, 14);
        cout<<"+-----------------------+";

        gotoxy(48, 15);
        cout<<"+-----------------------+";
        gotoxy(46, 16);
        cout<<"  |         Atras         |";
				gotoxy(48, 17);
        cout<<"+-----------------------+";

				break;

      //$ RESERVAR
			case 2:
				gotoxy(48, 9);
        cout<<"+-----------------------+";
        gotoxy(46, 10);
        cout<<"  |     Listar Laptops    |";
        gotoxy(48, 11);
        cout<<"+-----------------------+";

        change_color(241);
        gotoxy(48, 12);
        cout<<"+-----------------------+";
        gotoxy(46, 13);
        cout<<"->|        Reservar       |";
				gotoxy(48, 14);
        cout<<"+-----------------------+";
        change_color(240);

        gotoxy(48, 15);
        cout<<"+-----------------------+";
        gotoxy(46, 16);
        cout<<"  |         Atras         |";
				gotoxy(48, 17);
        cout<<"+-----------------------+";

				break;

      //$ ATRAS
      case 3:
				gotoxy(48, 9);
        cout<<"+-----------------------+";
        gotoxy(46, 10);
        cout<<"  |     Listar Laptops    |";
        gotoxy(48, 11);
        cout<<"+-----------------------+";

        gotoxy(48, 12);
        cout<<"+-----------------------+";
        gotoxy(46, 13);
        cout<<"  |        Reservar       |";
				gotoxy(48, 14);
        cout<<"+-----------------------+";

        change_color(241);
        gotoxy(48, 15);
        cout<<"+-----------------------+";
        gotoxy(46, 16);
        cout<<"->|         Atras         |";
				gotoxy(48, 17);
        cout<<"+-----------------------+";
        change_color(240);

				break;
		}
		
		tecla = _getch();
  }

  switch(opc){
    case 1:
      LaptopMain::listar_laptops();
      break;
    case 2:
      gestor.cambiar_ventana(Ventanas::LAPTOPRESERVA);
      break;
    case 3:
      gestor.cambiar_ventana(Ventanas::USERMAIN);
      break;
  }
}

void LaptopMain::main(GestorVentanas& gestor) {
  LaptopMain::mostrar();
  LaptopMain::seleccionar_opcion(gestor);
}