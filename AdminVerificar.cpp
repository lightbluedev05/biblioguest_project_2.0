#include "GestorVentanas.h"
#include "AdminVerificar.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <conio.h>
#include <cstdlib>

using namespace std;
string AdminVerificar::codigo_estudiante;
string AdminVerificar::codigo_encontrado;
string AdminVerificar::codigo_busqueda;
vector<vector<string>> AdminVerificar::reservas_historial;
char AdminVerificar::letra;
int AdminVerificar::aux;

void AdminVerificar::mostrar(GestorVentanas& gestor){
    change_color(112);
    system("cls");
    show_cursor();

    change_color(240);
    rectangle(67, 22, 27, 3);

    change_color(244);
    gotoxy(52, 4);
    cout << " VERIFICAR RESERVAS ";

    change_color(240);
    gotoxy(42, 7);
    cout << "Codigo del estudiante: #";
    rectangle(15, 1, 66, 6);

    rectangle(15, 1, 43, 22);
    gotoxy(46,23);
    cout << "CONFIRMAR";

    rectangle(15, 1, 63, 22);
    gotoxy(68,23);
    cout << "ATRAS";

    change_color(113);
    gotoxy(40, 27);
    cout << "UTILIZE LAS FLECHAS PARA SELECCIONAR LAS";
    gotoxy(45, 28);
    cout << "OPCIONES (IZQUIERDA Y DERECHA)";
    change_color(240);
}

void AdminVerificar::ingresar_codigo(GestorVentanas& gestor){
    vector<vector<string>> data_entrada;
    string linea_entrada;
    ifstream fileentrada("reservas_data.csv");

    while(getline(fileentrada, linea_entrada)) {
        vector<string> horariosentrada = {};
        string horarioentrada = "";
        stringstream ss(linea_entrada);

        while(getline(ss, horarioentrada, ',')) {
            horariosentrada.push_back(horarioentrada);
        }
        data_entrada.push_back(horariosentrada);
    }
    fileentrada.close();

    AdminVerificar::codigo_encontrado = "no";

    int contador=0;

    do {

        if (contador > 0) {
            change_color(244);
            gotoxy(56,11);
            cout<<"ERROR";
            change_color(240);
        }
        gotoxy(67,7);
        cout << "             ";
        gotoxy(67,7);
        cin >> AdminVerificar::codigo_estudiante;
        for (int i = 0; i < data_entrada.size(); i++) {
          if (data_entrada[i][3] == AdminVerificar::codigo_estudiante) {
              AdminVerificar::codigo_encontrado = "si";
              AdminVerificar::aux = i;
              break;
          }
        }
        contador++;
    } while (AdminVerificar::codigo_encontrado == "no");
    change_color(250);
    gotoxy(56,11);
    cout<<"CORRECTO";
    change_color(240);
    hide_cursor();
    AdminVerificar::opciones(gestor);
    getch();
}

void AdminVerificar::opciones(GestorVentanas& gestor){
    int opcaux;
    string codigo_cubiculo="", horario="", codigo_alumno="";
    string codigo_laptop="";

    //* CONSEGUIR DATA DE RESERVAS
    vector<vector<string>> data;
    string linea;
    ifstream file("reservas_data.csv");

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

    //* BUSCAR Y ASIGNAR RESERVA DEL DIA DE HOY
    for(int i=0; i<data.size(); i++){
      if(data[i][3]==AdminVerificar::codigo_estudiante){
        codigo_alumno = data[i][2];
        AdminVerificar::codigo_busqueda = data[i][2];
        if(data[i][0][0]=='C'){
          codigo_cubiculo = data[i][0];
          horario = data[i][1];
          opcaux=0;
          AdminVerificar::letra = 'C';
        } else if (data[i][0][0]=='L'){
          codigo_laptop = data[i][0];
          horario = data[i][1];
          opcaux=1;
          AdminVerificar::letra = 'L';
        }
      }
    }

    string horario_letra;

    switch(stoi(horario)){
      case 1:
        horario_letra = "8am - 10am";
        break;
      case 2:
        horario_letra = "10am - 12pm";
        break;
      case 3:
        horario_letra = "12pm - 2pm";
        break;
      case 4:
        horario_letra = "2pm - 4pm";
        break;
      case 5:
        horario_letra = "4pm - 6pm";
        break;
      case 6:
        horario_letra = "6pm - 8pm";
        break;
    }
    change_color(240);
    switch(opcaux){
      case 0:
        gotoxy(42, 17);
        cout<<"   Cubiculo  : "<<codigo_cubiculo;
        break;    
      case 1:
        gotoxy(42, 17);
        cout<<"   Laptop    : "<<codigo_laptop;
        break;
    }

    change_color(240);
    gotoxy(42, 15);
    cout<<"   Codigo    : "<<codigo_alumno;
    gotoxy(42, 19);
    cout<<"   Horario   : "<<horario_letra;

    confirmar(gestor);

}

void AdminVerificar::confirmar(GestorVentanas& gestor){
  int opc=1, tecla=75;
  while(tecla!=13){
    switch(tecla){
			case 75:
        change_color(241);
        rectangle(15, 1, 43, 22);
        gotoxy(46,23);
        cout << "CONFIRMAR";
        change_color(240);

        rectangle(15, 1, 63, 22);
        gotoxy(68,23);
        cout << "ATRAS";

				opc=0;
				break;
			case 77:
        rectangle(15, 1, 43, 22);
        gotoxy(46,23);
        cout << "CONFIRMAR";

        change_color(241);
        rectangle(15, 1, 63, 22);
        gotoxy(68,23);
        cout << "ATRAS";
        change_color(240);
				
				opc=1;
				break;
		}
    tecla = _getch();
  }

  switch(opc) {
      case 0: {
          vector<vector<string>> data_ultimo;
          string linea_ultimo;
          ifstream fileultimo("reservas_data.csv");

          while(getline(fileultimo, linea_ultimo)) {
              vector<string> horariosultimo = {};
              string horarioultimo = "";
              stringstream ss(linea_ultimo);

              while(getline(ss, horarioultimo, ',')) {
                  horariosultimo.push_back(horarioultimo);
              }
              data_ultimo.push_back(horariosultimo);
          }
          fileultimo.close();

          for (int i = 0; i < data_ultimo.size(); i++){
              if (data_ultimo[i][2] == AdminVerificar::codigo_busqueda){
                if(AdminVerificar::letra == data_ultimo[i][0][0]){
                  data_ultimo.erase(data_ultimo.begin() + i);
                  break;
                }
              }
          }


          ofstream file_ultimo("reservas_data.csv");
          for(int t=0; t<data_ultimo.size(); t++){
            file_ultimo << data_ultimo[t][0] << "," << data_ultimo[t][1] << "," << data_ultimo[t][2]<< "," << data_ultimo[t][3] << endl;
          }

          file_ultimo.close();

          ifstream file_5("reservas_history.csv");
          string linea_5;

          AdminVerificar::reservas_historial.clear();

          // Leer datos desde el archivo CSV y almacenar en reservas_historial
          while (getline(file_5, linea_5)) {
              vector<string> reservas = {};
              string reserva = "";
              stringstream ss(linea_5);

              while (getline(ss, reserva, ',')) {
                  reservas.push_back(reserva);
              }

              AdminVerificar::reservas_historial.push_back(reservas);
          }

          file_5.close();

          for(int i = 0; i < AdminVerificar::reservas_historial.size(); i++){
            if(AdminVerificar::reservas_historial[i][0] == AdminVerificar::codigo_estudiante){
              AdminVerificar::reservas_historial[i][7] = "SI";
              break;
            }
          }

          ofstream file_6("reservas_history.csv");

          for (int i = 0; i < AdminVerificar::reservas_historial.size(); i++) {
              for (int j = 0; j < AdminVerificar::reservas_historial[i].size(); j++) {
                  file_6 << AdminVerificar::reservas_historial[i][j];
                  if (j < AdminVerificar::reservas_historial[i].size() - 1) {
                      file_6 << ",";
                  }
              }
              file_6 << "\n";
          }

          file_6.close();


          gestor.cambiar_ventana(Ventanas::ADMINMAIN);
          break;
      }
    case 1:
      gestor.cambiar_ventana(Ventanas::ADMINMAIN);
      break;
  }
}

void AdminVerificar::main(GestorVentanas& gestor){
    AdminVerificar::mostrar(gestor);
    AdminVerificar::ingresar_codigo(gestor);
}