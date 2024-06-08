#include "GestorVentanas.h"
#include "CubiculosReserva.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "functions.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>
#include <ctime>
#include <vector>


using namespace std;

//$ INICIALIZACION
string CubiculosReserva::codigo_cubiculo;
string CubiculosReserva::horario_cubiculo;
vector<vector<string>> CubiculosReserva::horarios_data;
vector<vector<string>> CubiculosReserva::reservas_data;
vector<vector<int>> CubiculosReserva::historial;

bool cubiculo_valido(const string& codigo) {
  set<string> codigos_validos = {"1A01", "1A02", "1A03", "1A04", "2A01", "2A02", "2A03", "2A04"};

  return find(codigos_validos.begin(), codigos_validos.end(), codigo) != codigos_validos.end();
}


void CubiculosReserva::mostrar(){
  change_color(112);
  system("cls");
  show_cursor();

  change_color(240);
  rectangle(67, 19, 27, 3);

  change_color(244);
  gotoxy(52, 4);
  cout<<"RESERVA DE CUBICULOS";

  change_color(240);
  gotoxy(44, 7);
  cout<<"Codigo del cubiculo: #";
  rectangle(15, 1, 66, 6);

  rectangle(15, 1, 33, 10);
  gotoxy(36,11);
  cout<<"08am-10am";

  rectangle(15, 1, 53, 10);
  gotoxy(56,11);
  cout<<"10am-12pm";

  rectangle(15, 1, 73, 10);
  gotoxy(76,11);
  cout<<"12pm-02pm";

  rectangle(15, 1, 33, 15);
  gotoxy(36,16);
  cout<<"02pm-04pm";

  rectangle(15, 1, 53, 15);
  gotoxy(56,16);
  cout<<"04pm-06pm";

  rectangle(15, 1, 73, 15);
  gotoxy(76,16);
  cout<<"06pm-08pm";

  rectangle(14, 1, 44, 19);
  gotoxy(47,20);
  cout<<"RESERVAR";

  rectangle(15, 1, 63, 19);
  gotoxy(68,20);
  cout<<"ATRAS";

}

void CubiculosReserva::conseguir_data(){
  //$ HORARIOS_DATA.CSV
  ifstream file("horarios_data.csv");
  string linea;

  CubiculosReserva::horarios_data.clear();

  while(getline(file, linea)){
    vector<string> horarios={};
    string horario="";
    stringstream ss(linea);

    while(getline(ss, horario, ',')){
      horarios.push_back(horario);
    }
    CubiculosReserva::horarios_data.push_back(horarios);
  }
  file.close();

  //$ RESERVAS_DATA.CSV
  ifstream file2("reservas_data.csv");
  string linea2;

  CubiculosReserva::reservas_data.clear();
  while(getline(file2, linea2)){
    vector<string> reservas={};
    string reserva="";
    stringstream ss2(linea2);

    while(getline(ss2, reserva, ',')){
      reservas.push_back(reserva);
    }
    CubiculosReserva::reservas_data.push_back(reservas);
  }
  file2.close();

  //$ CUBICULOS_HISTORY.CSV
  ifstream file3("cubiculos_history.csv");
  string linea3;

  CubiculosReserva::historial.clear();
  while(getline(file3, linea3)){
    vector<int> history;
    string valor;
    stringstream ss3(linea3);

    while(getline(ss3, valor, ',')){
      history.push_back(stoi(valor));
    }
    CubiculosReserva::historial.push_back(history);
  }
  file3.close();
}

void CubiculosReserva::ingresar_datos(GestorVentanas& gestor){
  int controlador=0;
  do{
    controlador++;
    if(controlador>4){
      gotoxy(98, 6);
      cout<<"REVISA BIEN EL CODIGO";
      gotoxy(98,7);
      cout<<"DEL CUBICULO :)";
      gotoxy(98,8);
      cout<<"PRESIONA ENTER";
      getch();
      gestor.cambiar_ventana(Ventanas::CUBICULOSMAIN);
      return;
    }
    gotoxy(67,7);
    cout<<"             ";
    gotoxy(67,7);
    cin>>CubiculosReserva::codigo_cubiculo;
  } while(!cubiculo_valido(CubiculosReserva::codigo_cubiculo));

  //$ SELECCION DE HORARIO
  int aux_x=0, aux_y=0, tecla=75;

  while(tecla!=13){
    switch (tecla){
      case 75:
        if(aux_x>0){
          aux_x--;
        }
        break;

      case 77:
        if(aux_x<2){
          aux_x++;
        }
        break;

      case 72:
        if(aux_y>0){
          aux_y--;
        }
        break;

      case 80:
        if(aux_y<1){
          aux_y++;
        }
        break;
    }

    if(aux_x==0 && aux_y==0){change_color(113); CubiculosReserva::horario_cubiculo = "1";}
    rectangle(15, 1, 33, 10);
    gotoxy(36,11);
    cout<<"08am-10am";
    change_color(240);

    if(aux_x==1 && aux_y==0){change_color(113); CubiculosReserva::horario_cubiculo = "2";}
    rectangle(15, 1, 53, 10);
    gotoxy(56,11);
    cout<<"10am-12pm";
    change_color(240);

    if(aux_x==2 && aux_y==0){change_color(113); CubiculosReserva::horario_cubiculo = "3";}
    rectangle(15, 1, 73, 10);
    gotoxy(76,11);
    cout<<"12pm-02pm";
    change_color(240);

    if(aux_x==0 && aux_y==1){change_color(113); CubiculosReserva::horario_cubiculo = "4";}
    rectangle(15, 1, 33, 15);
    gotoxy(36,16);
    cout<<"02pm-04pm";
    change_color(240);

    if(aux_x==1 && aux_y==1){change_color(113); CubiculosReserva::horario_cubiculo = "5";}
    rectangle(15, 1, 53, 15);
    gotoxy(56,16);
    cout<<"04pm-06pm";
    change_color(240);

    if(aux_x==2 && aux_y==1){change_color(113); CubiculosReserva::horario_cubiculo = "6";}
    rectangle(15, 1, 73, 15);
    gotoxy(76,16);
    cout<<"06pm-08pm";
    change_color(240);

		tecla = _getch();
  }
  
  int opc=0;
  tecla=75;
  //$ SELECCION DE OPCION
  while(tecla!=13){
    switch(tecla){
      case 75:
        change_color(241);
        rectangle(14, 1, 44, 19);
        gotoxy(46,20);
        cout<<"*RESERVAR";
        change_color(240);

        rectangle(15, 1, 63, 19);
        gotoxy(68,20);
        cout<<"ATRAS";
        opc=0;
        break;

      case 77:
        rectangle(14, 1, 44, 19);
        gotoxy(47,20);
        cout<<"RESERVAR";

        change_color(241);
        rectangle(15, 1, 63, 19);
        gotoxy(67,20);
        cout<<"*ATRAS";
        change_color(240);
        opc=1;
        break;
    }
    tecla = _getch();
  }

  switch(opc){
    case 0:
      CubiculosReserva::comprobacion_de_datos(gestor);
      break;
    case 1:
      gestor.cambiar_ventana(Ventanas::CUBICULOSMAIN);
      break;
  }

}

void CubiculosReserva::comprobacion_de_datos(GestorVentanas& gestor){
  vector<vector<string>> data = CubiculosReserva::horarios_data;
  vector<vector<string>> r_data = CubiculosReserva::reservas_data;
  int busqueda=0, horario_aux, linea;

  for(int i=0; i<r_data.size(); i++){
    if(r_data[i][2]==gestor.codigo && r_data[i][0][1]=='A'){
      //$ CODIGO YA UTILIZADO
      busqueda=3;
      break;
    }
  }

  if(busqueda!=3){
    time_t tiempoActual = time(NULL);
    tm* tiempoLocal = localtime(&tiempoActual);
    int horaActual = tiempoLocal->tm_hour;

    // Definir los horarios límite
    int horaInicio, horaFin;

    // Establecer los horarios límite según el horario seleccionadoa
    switch (stoi(CubiculosReserva::horario_cubiculo)) {
        case 1:
            horaFin = 10;
            break;
        case 2:
            horaFin = 12;
            break;
        case 3:
            horaFin = 14;
            break;
        case 4:
            horaFin = 16;
            break;
        case 5:
            horaFin = 18;
            break;
        case 6:
            horaFin = 20;
            break;
    }
    if (horaActual >= horaFin) {
        busqueda=4;
    }
  }

  if(busqueda!=3 && busqueda!=4){
    for(int i=0; i<data.size(); i++){
      if(data[i][0]==CubiculosReserva::codigo_cubiculo){
        linea = i;
        horario_aux = stoi(CubiculosReserva::horario_cubiculo);
        if(data[i][horario_aux] == "1"){
          //$ HORARIO OCUPADO
          busqueda=1;
        } else {
          //$ HORARIO DISPONIBLE
          busqueda=2;
        }
        break;
      }
    }
  }
  
  system("cls");

  switch(busqueda){
    case 0:
      gotoxy(50, 20);
      cout<<"NO SE HA ENCONTRADO ESTE CODIGO DE CUBICULO";
      break;
    case 1:
      gotoxy(45, 12);
      cout<<"ESTE HORARIO YA ESTA RESERVADO";
      change_color(241);
      gotoxy(41,13);
      cout<<"PRESIONE CUALQUIER TECLA PARA CONTINUAR";
      change_color(240);
      gestor.cambiar_ventana(Ventanas::CUBICULOSMAIN);
      break;
    case 2:
      ejecutar_reserva(gestor, linea, horario_aux);
      gotoxy(45, 12);
      cout<<"RESERVA EJECUTADA CON EXITO :)";
      change_color(241);
      gotoxy(41,13);
      cout<<"PRESIONE CUALQUIER TECLA PARA CONTINUAR";
      change_color(240);
      gestor.cambiar_ventana(Ventanas::CUBICULOSMAIN);
      break;
    case 3:
      gotoxy(44, 12);
      cout<<"YA HAS EJECUTADO UNA RESERVA HOY";
      change_color(241);
      gotoxy(41,13);
      cout<<"PRESIONE CUALQUIER TECLA PARA CONTINUAR";
      change_color(240);
      gestor.cambiar_ventana(Ventanas::CUBICULOSMAIN);
      break;
    case 4:
      gotoxy(25, 10);
      cout<<"--------¡¡¡¡¡¡¡¡¡¡¡¡ESTAS FUERA DE HORA!!!!!!!!!!!!!!--------";
      change_color(241);
      gotoxy(34,11);
      cout<<"REVISA LOS HORARIOS DISPONIBLES EN LA LISTA DE CUBICULOS";
      change_color(240);
      gestor.cambiar_ventana(Ventanas::CUBICULOSMAIN);
      break;
  }

  getch();
}

void CubiculosReserva::ejecutar_reserva(GestorVentanas& gestor, int laptop, int horario){
  ofstream file("horarios_data.csv");
  
  vector<vector<string>> data = CubiculosReserva::horarios_data;

  data[laptop][horario] = "1";
  
  for(int i=0; i<data.size(); i++){
    for(int j=0; j<data[i].size(); j++){
      file<<data[i][j];
      if(j<data[i].size()-1){
        file<<",";
      }
    }
    file<<"\n";
  }

  file.close();

  ofstream file_2("reservas_data.csv", ios::app);
  file_2<<CubiculosReserva::codigo_cubiculo<<","<<CubiculosReserva::horario_cubiculo<<","<<gestor.codigo<<"\n";
  file_2.close();

  for(int i = 0; i < CubiculosReserva::historial.size(); i++) {
    int aux = stoi(CubiculosReserva::horario_cubiculo);
      if(CubiculosReserva::historial[i][0] == aux) {
          CubiculosReserva::historial[i][1]++;
          break;
      }
  }

  ofstream file_3("cubiculos_history.csv");

  for(int i = 0; i < CubiculosReserva::historial.size(); i++) {
    for(int j = 0; j < CubiculosReserva::historial[i].size(); j++) {
      file_3<<CubiculosReserva::historial[i][j];
      if(j < CubiculosReserva::historial[i].size() - 1) {
          file_3<<",";
      }
    }
    file_3<<"\n";
  }
  file_3.close();
}

void CubiculosReserva::main(GestorVentanas& gestor){
  CubiculosReserva::mostrar();
  CubiculosReserva::conseguir_data();
  CubiculosReserva::ingresar_datos(gestor);
}