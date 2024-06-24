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
#include <cmath>

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

void dibujar_ventana(int ventana_actual, vector<vector<string>> data, int numero_ventanas){
  int n=data.size();
  int inicio = (ventana_actual-1)*6;
  int final;

  //$ BARRA DE DESPLAZAMIENTO
  change_color(240);
  gotoxy(30,5);
  for(int i=0; i<60; i++){
    cout<<"=";
  }

  int longitud_barra = 60/numero_ventanas;

  change_color(241);
  gotoxy(30+((ventana_actual-1)*longitud_barra), 5);
  for(int i=0; i<longitud_barra; i++){
    cout<<"=";
  }
  change_color(240);

  //$ LIMPIEZA HORARIOS
  for(int i=0; i<21; i++){
    gotoxy(26, 7+i);
    cout<<"                                                                                    ";
  }

  //$ HORARIOS
  if(n>inicio+6){
    final=inicio+5;
  } else {
    final = n-1;
  }

  for(int i=inicio; i<=final; i++){
    change_color(241);
    button(14, 1, 21+(15*(i-inicio)), 12, data[i][0]);
    
    rectangle(14, 3, 21+(15*(i-inicio)), 8);
    gotoxy(22+(15*(i-inicio)), 9);
    cout<<">";
    if(data[i][7]!="n"){cout<<data[i][7];}
    gotoxy(22+(15*(i-inicio)), 10);
    cout<<">";
    if(data[i][8]!="n"){cout<<data[i][8];}
    gotoxy(22+(15*(i-inicio)), 11);
    cout<<">";
    if(data[i][9]!="n"){cout<<data[i][9];}

    
    if(data[i][10]!="Habilitado"){
      change_color(244);
      for(int j=0; j<data[i][10].length(); j++){
        gotoxy(27+((i-inicio)*15), 15+j);
        cout<<data[i][10][j];
      }
    } else {
      for(int j=0; j<6; j++){
        string aux="";
        if(data[i][j+1]=="1"){
          aux="No";
          change_color(244);
        } else {
          aux="Si";
          change_color(242);
        }

        button(14, 1, 21+(15*(i-inicio)), 15+(j*2), aux);
      }
    }
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
    if(horarios[0][0]=='L'){
      data.push_back(horarios);
    }
  }
  file.close();

  //*----------IMPRIMIR DATA DE LAPTOPS-------------
  change_color(112);
  system("cls");

  change_color(240);
  rectangle(107, 26, 5, 1);
  gotoxy(13, 2);
  cout<<"Verifica que laptops";
  gotoxy(13, 3);
  cout<<"estan disponibles...";

  change_color(241);
  gotoxy(50, 3);
  cout<<"LISTA DE LAPTOPS";

  button(13, 1, 7, 15, "08AM-10AM");
  button(13, 1, 7, 17, "10AM-12PM");
  button(13, 1, 7, 19, "12PM-02PM");
  button(13, 1, 7, 21, "02PM-04PM");
  button(13, 1, 7, 23, "04PM-06PM");
  button(13, 1, 7, 25, "06PM-08PM");

  int numero_laptops = data.size();
  int numero_ventanas = ceil(numero_laptops/6.0);

  int tecla=75;
  int ventana_actual=1;
  while(tecla!=13){
    dibujar_ventana(ventana_actual, data, numero_ventanas);
    
    tecla=_getch();

    if(tecla==75 && ventana_actual>1){
      ventana_actual--;
    } else if (tecla==77 && ventana_actual<numero_ventanas){
      ventana_actual++;
    }
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