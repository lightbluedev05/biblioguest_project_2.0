#include "CubiculosMain.h"
#include "GestorVentanas.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

void escoger_color(int valor){
  if(valor==1){
    change_color(244);
  } else {
    change_color(240);
  }
}

void pintar_cubiculo(int cubiculo[], int x, int y){
  escoger_color(cubiculo[0]);
  gotoxy(x, y);
  cout<<"08am-10am";

  escoger_color(cubiculo[1]);
  cout<<"  10am-12pm";

  escoger_color(cubiculo[2]);
  cout<<"  12pm-02pm";

  escoger_color(cubiculo[3]);
  gotoxy(x, y+1);
  cout<<"02pm-04pm";

  escoger_color(cubiculo[4]);
  cout<<"  04pm-06pm";

  escoger_color(cubiculo[5]);
  cout<<"  06pm-08pm";

  change_color(240);
}

void CubiculosMain::mostrar() {
  change_color(112);
  system("cls");

  change_color(240);
  rectangle(46, 19, 37, 3);

  change_color(244);
  gotoxy(53,4);
  cout<<"MENU DE CUBICULOS";

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


void dibujar_ventana2(int ventana_actual, vector<vector<string>> data, int numero_ventanas){
  int n=data.size();
  int inicio = (ventana_actual-1)*6;
  int final;

  //$ INDICADOR DE VENTANA
  ostringstream numero_ventana;
  numero_ventana<<setw(2)<<setfill('0')<<(ventana_actual);
  ostringstream total_ventanas;
  total_ventanas<<setw(2)<<setfill('0')<<numero_ventanas;
  change_color(241);
  gotoxy(88, 26);
  cout<<"<--Pagina "<<numero_ventana.str()<<" / "<<total_ventanas.str()<<"-->";
  change_color(240);

  //$ LIMPIEZA HORARIOS
  for(int i=0; i<19; i++){
    gotoxy(20, 7+i);
    for(int j=0; j<90; j++){
      cout<<" ";
    }
  }

  //$ HORARIOS
  if(n>inicio+6){
    final=inicio+5;
  } else {
    final = n-1;
  }

  for(int i=inicio; i<=final; i++){
    change_color(241);
    button(14, 1, 21+(15*(i-inicio)), 9, data[i][0]);

    string aux="Cap.: "+data[i][8];
    button(14, 1, 21+(15*(i-inicio)), 7, aux);
    
    if(data[i][7]!="Habilitado"){
      change_color(244);
      for(int j=0; j<data[i][7].length(); j++){
        gotoxy(27+((i-inicio)*15), 12+j);
        cout<<data[i][7][j];
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

        button(14, 1, 21+(15*(i-inicio)), 12+(j*2), aux);
      }
    }
  }
}


void CubiculosMain::listar_cubiculos() {

  //*----------CONSEGUIR DATA DE CUBICULOS-------------
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
    if(horarios[0][0]=='C'){
      data.push_back(horarios);
    }
  }
  file.close();

  //*----------IMPRIMIR DATA DE CUBICULOS-------------
  change_color(112);
  system("cls");

  change_color(240);
  rectangle(107, 24, 5, 1);
  gotoxy(13, 3);
  cout<<"Verifica que cubiculos";
  gotoxy(13, 4);
  cout<<"estan disponibles...";

  change_color(241);
  gotoxy(50, 3);
  cout<<"LISTA DE CUBICULOS";

  button(13, 1, 7, 12, "08AM-10AM");
  button(13, 1, 7, 14, "10AM-12PM");
  button(13, 1, 7, 16, "12PM-02PM");
  button(13, 1, 7, 18, "02PM-04PM");
  button(13, 1, 7, 20, "04PM-06PM");
  button(13, 1, 7, 22, "06PM-08PM");

  int numero_laptops = data.size();
  int numero_ventanas = ceil(numero_laptops/6.0);

  int tecla=75;
  int ventana_actual=1;
  while(tecla!=13){
    dibujar_ventana2(ventana_actual, data, numero_ventanas);
    
    tecla=_getch();

    if(tecla==75 && ventana_actual>1){
      ventana_actual--;
    } else if (tecla==77 && ventana_actual<numero_ventanas){
      ventana_actual++;
    }
  }

  getch();
}

void CubiculosMain::seleccionar_opcion(GestorVentanas& gestor) {
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
        cout<<"->|    Listar Cubiculos   |";
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
        cout<<"  |    Listar Cubiculos   |";
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
        cout<<"  |    Listar Cubiculos   |";
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
      CubiculosMain::listar_cubiculos();
      break;
    case 2:
      gestor.cambiar_ventana(Ventanas::CUBICULOSRESERVA);
      break;
    case 3:
      gestor.cambiar_ventana(Ventanas::USERMAIN);
      break;
  }
}

void CubiculosMain::main(GestorVentanas& gestor) {
  CubiculosMain::mostrar();
  CubiculosMain::seleccionar_opcion(gestor);
}