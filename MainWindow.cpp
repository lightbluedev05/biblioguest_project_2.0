#include "MainWindow.h"
#include "GestorVentanas.h"
#include "functions.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;

void MainWindow::mostrar(){
  change_color(116);
  system("cls");

  change_color(240);
  rectangle(59, 23, 27, 1);
  gotoxy(40,8);
  cout << "Bienvenido al Sistema de Gestion";
  gotoxy(37,9);
  cout << "de reserva de la Biblioteca de la UNMSM";

  gotoxy(32, 23);
  cout << "UTILIZE LAS FLECHAS PARA SELECCIONAR LAS OPCIONES";

  gotoxy(47, 24);
  cout << "(Arriba y Abajo)";

  change_color(244);
  gotoxy(33,2);
  cout << " ____  _ __    ___       ______                __ "<<endl;
  
  gotoxy(32,3);
  cout << " / __ )(_) /_  / (_)___  / ____/_  _____  _____/ /_"<<endl;
  
  gotoxy(31,4);
  cout << " / __  / / __ |/ / / __ |/ / __/ / / / _ |/ ___/ __/"<<endl;
  
  gotoxy(30,5);
  cout << " / /_/ / / /_/ / / / /_/ / /_/ / /_/ /  __(__  ) /_ "<<endl;
  
  gotoxy(30,6);
  cout << "/_____/_/_____/_/_/|____/|____/|____/|___/____/|__/"<<endl;

}

void MainWindow::seleccionar_ventana(GestorVentanas& gestor){
  int opc=1, tecla=72;
  while(tecla!=13){
    switch(tecla){
      case 72: 
        change_color(241);
        gotoxy(44, 12);
        cout << "+-----------------------+";
        gotoxy(42, 13);
        cout << "->|     Ingresar como     |";
        gotoxy(44, 14);
        cout << "|       un Alumno       |";
        gotoxy(44, 15);
        cout << "+-----------------------+";

        change_color(240);
        gotoxy(44, 17);
        cout << "+-----------------------+";
        gotoxy(42, 18);
        cout << "  |     Ingresar como     |";
        gotoxy(44, 19);
        cout << "|     Administrador     |";
        gotoxy(44, 20);
        cout << "+-----------------------+";

        opc=1;
        break;
      case 80:
        change_color(240);
        gotoxy(44, 12);
        cout << "+-----------------------+";
        gotoxy(42, 13);
        cout << "  |     Ingresar como     |";
        gotoxy(44, 14);
        cout << "|       un Alumno       |";
        gotoxy(44, 15);
        cout << "+-----------------------+";

        change_color(241);
        gotoxy(44, 17);
        cout << "+-----------------------+";
        gotoxy(42, 18);
        cout << "->|     Ingresar como     |";
        gotoxy(44, 19);
        cout << "|     Administrador     |";
        gotoxy(44, 20);
        cout << "+-----------------------+";
        
        opc=0;
        break;
    }
    
    tecla = _getch();
  }

  switch(opc){
    case 1:
      gestor.cambiar_ventana(Ventanas::USERLOGIN);
      break;
    case 0:
      gestor.cambiar_ventana(Ventanas::ADMINLOGIN);
      break;
  }

}

void MainWindow::borrar(GestorVentanas& gestor){
  vector<vector<string>> h_data;
  string linea2;
  ifstream file2("horarios_data.csv");

  while(getline(file2, linea2)){
    vector<string> horarios={};
    string horario="";
    stringstream ss(linea2);

    while(getline(ss, horario, ',')){
      horarios.push_back(horario);
    }
    h_data.push_back(horarios);
  }
  file2.close();

  for(int i = 0; i < h_data.size(); i++){
    h_data[i][1] = "0";
    h_data[i][2] = "0";
    h_data[i][3] = "0";
    h_data[i][4] = "0";
    h_data[i][5] = "0";
    h_data[i][6] = "0";
  }

  ofstream file3("horarios_data.csv");

  for (int i = 0; i < h_data.size(); i++) {
      for (int j = 0; j < h_data[i].size(); j++) {
          file3 << h_data[i][j];
          if (j < h_data[i].size() - 1) {
              file3 << ",";
          }
      }
      file3 << "\n";
  }

  file3.close(); 
}

void MainWindow::cargar_sanciones(GestorVentanas& gestor){
  time_t tiempoActual = time(NULL);
  tm* tiempoLocal = localtime(&tiempoActual);
  int horaActual = tiempoLocal->tm_hour;
  int minActual = tiempoLocal->tm_min;
  int horaInicio, horaFin;

  vector<vector<string>> reservas_data;
  string linea;
  ifstream file("reservas_data.csv");

  while(getline(file, linea)){
    vector<string> reservas={};
    string reserva="";
    stringstream ss(linea);

    while(getline(ss, reserva, ',')){
      reservas.push_back(reserva);
    }
    reservas_data.push_back(reservas);
  }
  file.close();

  vector<vector<string>> historial_sanciones;
  string linea_h;
  ifstream file_sanciones("sanciones.csv");

  while(getline(file_sanciones, linea_h)){
    vector<string> history_sanciones;
    string valor1;
    stringstream ss3(linea_h);

    while(getline(ss3, valor1, ',')){
      history_sanciones.push_back(valor1);
    }
    historial_sanciones.push_back(history_sanciones);
  }
  file_sanciones.close();

  for (int t = 0; t < historial_sanciones.size(); t++) {
      int codigo = stoi(historial_sanciones[t][0]); //codigo = 23200338
      for (auto it = reservas_data.begin(); it != reservas_data.end(); ) {
          if ((*it)[2] == to_string(codigo)) { // data[i][2]=23200338
              int aux = stoi((*it)[1]); // data[i][1] es el horario

              int horaFin;
              switch (aux) {
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

              if ((horaActual >= horaFin || horaActual < 8) && minActual >= 0) {
                  int incremento = stoi(historial_sanciones[t][1]); // Incremento convertido a entero si es necesario
                  historial_sanciones[t][1] = to_string(incremento + 1); // Incremento y asignación como string
                  it = reservas_data.erase(it); // Eliminar y avanzar el iterador
              } else {
                  ++it; // Solo avanzar el iterador
              }
          } else {
              ++it; // Solo avanzar el iterador
          }
      }
  }

  ofstream file21("sanciones.csv");
  for(int t=0; t<historial_sanciones.size(); t++){
    file21 << historial_sanciones[t][0] << "," << historial_sanciones[t][1] << endl;
  }
  file21.close();


  
  ofstream file31("reservas_data.csv");
  for(int t=0; t<reservas_data.size(); t++){
    file31 << reservas_data[t][0] << "," << reservas_data[t][1] << "," << reservas_data[t][2] << "," << reservas_data[t][3] << endl;
  }
  file31.close();

  if(horaActual>=20 || horaActual<=8){
    borrar(gestor);
  }
}

void MainWindow::main(GestorVentanas& gestor){
  MainWindow::cargar_sanciones(gestor);
  MainWindow::mostrar();
  MainWindow::seleccionar_ventana(gestor);
}