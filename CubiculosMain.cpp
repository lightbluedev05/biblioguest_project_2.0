#include "CubiculosMain.h"
#include "GestorVentanas.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <cstdlib>

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

void CubiculosMain::listar_cubiculos() {
  //$ OBTENCION DE HORARIOS_DATA
  ifstream horarios("horarios_data.csv");
  string linea;
  vector<vector<string>> h_data;
  while(getline(horarios, linea)){
    vector<string> aux={};
    stringstream ss(linea);
    string aux2;
    while(getline(ss, aux2, ',')){
      aux.push_back(aux2);
    }
    h_data.push_back(aux);
  }
  horarios.close();
  
  int cubiculo101[6]={0,0,0,0,0,0};
  int cubiculo102[6]={0,0,0,0,0,0};
  int cubiculo103[6]={0,0,0,0,0,0};
  int cubiculo104[6]={0,0,0,0,0,0};
  int cubiculo201[6]={0,0,0,0,0,0};
  int cubiculo202[6]={0,0,0,0,0,0};
  int cubiculo203[6]={0,0,0,0,0,0};
  int cubiculo204[6]={0,0,0,0,0,0};

  for(int i=0; i<6; i++){
    cubiculo101[i]=stoi(h_data[21][i+1]);
    cubiculo102[i]=stoi(h_data[22][i+1]);
    cubiculo103[i]=stoi(h_data[23][i+1]);
    cubiculo104[i]=stoi(h_data[24][i+1]);
    cubiculo201[i]=stoi(h_data[25][i+1]);
    cubiculo202[i]=stoi(h_data[26][i+1]);
    cubiculo203[i]=stoi(h_data[27][i+1]);
    cubiculo204[i]=stoi(h_data[28][i+1]);
  }

  //$ PINTADO DE CONSOLA
  change_color(112);
  system("cls");
  change_color(240);
  rectangle(90, 25, 15, 2);

  change_color(244);
  gotoxy(50,4);
  cout<<"LISTADO DE CUBICULOS";
  change_color(241);
  gotoxy(35,6);
  cout<<"Utilize las flechas (<- , ->) para cambiar de piso";

  gotoxy(40,26);
  cout<<"LOS HORARIOS EN ROJO YA ESTAN RESERVADOS";
  gotoxy(46,27);
  cout<<"Presione ENTER para salir...";

  change_color(240);
  rectangle(35, 4, 22, 12);
  rectangle(35, 4, 63, 12);
  rectangle(35, 4, 22, 19);
  rectangle(35, 4, 63, 19);

  //$ CAMBIO DE PISO
  int opc=1, tecla=75;
  while(tecla!=13){
    switch(tecla){
			case 75:
        change_color(241);
				gotoxy(37, 8);
        cout<<"+------------+";
        gotoxy(35, 9);
        cout<<"->|   PISO 1   |";
        gotoxy(37, 10);
        cout<<"+------------+";
        change_color(240);

        gotoxy(69, 8);
        cout<<"+------------+";
        gotoxy(67, 9);
        cout<<"  |   PISO 2   |";
        gotoxy(69, 10);
        cout<<"+------------+";

				opc=0;
				break;
			case 77:
				gotoxy(37, 8);
        cout<<"+------------+";
        gotoxy(35, 9);
        cout<<"  |   PISO 1   |";
        gotoxy(37, 10);
        cout<<"+------------+";

        change_color(241);
        gotoxy(69, 8);
        cout<<"+------------+";
        gotoxy(67, 9);
        cout<<"->|   PISO 2   |";
        gotoxy(69, 10);
        cout<<"+------------+";
        change_color(240);
				
				opc=1;
				break;
		}
		
    switch(opc){
      case 0:
        gotoxy(33,13);
        cout<<"CUBICULO #1A01";
        pintar_cubiculo(cubiculo101, 24, 15);
        gotoxy(74,13);
        cout<<"CUBICULO #1A02";
        pintar_cubiculo(cubiculo102, 65, 15);
        gotoxy(33,20);
        cout<<"CUBICULO #1A03";
        pintar_cubiculo(cubiculo103, 24, 22);
        gotoxy(74,20);
        cout<<"CUBICULO #1A04";
        pintar_cubiculo(cubiculo104, 65, 22);
        break;
      case 1:
        gotoxy(33,13);
        cout<<"CUBICULO #2A01";
        pintar_cubiculo(cubiculo201, 24, 15);
        gotoxy(74,13);
        cout<<"CUBICULO #2A02";
        pintar_cubiculo(cubiculo202, 65, 15);
        gotoxy(33,20);
        cout<<"CUBICULO #2A03";
        pintar_cubiculo(cubiculo203, 24, 22);
        gotoxy(74,20);
        cout<<"CUBICULO #2A04";
        pintar_cubiculo(cubiculo204, 65, 22);
        break;
    }
		tecla = _getch();
  }
  
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