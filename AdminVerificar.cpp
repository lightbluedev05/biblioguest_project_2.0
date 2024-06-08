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

struct User {
    string cod;
    string contra;
    string nombre;
};

vector<User> users;
string AdminVerificar::codigo_estudiante;
string AdminVerificar::codigo_encontrado;
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

    rectangle(15, 1, 39, 10);
    //+4
    gotoxy(43,11);
    cout << "Laptops";

    rectangle(15, 1, 67, 10);
    //+3
    gotoxy(70,11);
    cout << "Cubiculos";

    gotoxy(57,11);
    cout << "<----->";

    rectangle(15, 1, 43, 22);
    gotoxy(46,23);
    cout << "CONFIRMAR";

    rectangle(15, 1, 63, 22);
    gotoxy(68,23);
    cout << "ATRAS";
}

void AdminVerificar::ingresar_codigo(GestorVentanas& gestor){
    ifstream archivo("datos.txt");

    string line;

    while (getline(archivo, line)) {
        istringstream iss(line);
        User u;

        iss >> u.cod >> u.contra;
        getline(iss, u.nombre);

        users.push_back(u);
    }

    archivo.close();

    AdminVerificar::codigo_encontrado = "no";

    int contador=0;

    do {

        if (contador > 0) {
            change_color(244);
            gotoxy(85,7);
            cout<<"ERROR";
            change_color(240);
        }
        gotoxy(67,7);
        cout << "             ";
        gotoxy(67,7);
        cin >> AdminVerificar::codigo_estudiante;
        for (int i = 0; i < users.size(); i++) {
          if (stoi(users[i].cod) == stoi(AdminVerificar::codigo_estudiante)) {
              AdminVerificar::codigo_encontrado = "si";
              AdminVerificar::aux = i;
              break;
          }
        }
        contador++;
    } while (AdminVerificar::codigo_encontrado == "no");
    change_color(113);
    gotoxy(83,7);
    cout<<"CORRECTO";
    change_color(240);
    hide_cursor();
    AdminVerificar::opciones(gestor);
    getch();
}

void AdminVerificar::opciones(GestorVentanas& gestor){
  int opc=1, tecla=75;
  while(tecla!=13){
    switch(tecla){
			case 75:
        change_color(241);
        rectangle(15, 1, 39, 10);
        //+4
        gotoxy(43,11);
        cout << "Laptops";
        change_color(240);

        rectangle(15, 1, 67, 10);
        //+3
        gotoxy(70,11);
        cout << "Cubiculos";

				opc=0;
				break;
			case 77:
        rectangle(15, 1, 39, 10);
        //+4
        gotoxy(43,11);
        cout << "Laptops";

        change_color(241);
        rectangle(15, 1, 67, 10);
        //+3
        gotoxy(70,11);
        cout << "Cubiculos";
        change_color(240);
				
				opc=1;
				break;
		}
    tecla = _getch();
  }
    string codigo_cubiculo="", horario_cubiculo="", codigo_alumno="";
    string codigo_laptop="", horario_laptop="";

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
      if(data[i][2]==AdminVerificar::codigo_estudiante){
        codigo_alumno = data[i][2];
        if(data[i][0][1]=='A'){
          codigo_cubiculo = data[i][0];
          horario_cubiculo = data[i][1];
        } else {
          codigo_laptop = data[i][0];
          horario_laptop = data[i][1];
        }
      }
    }
    switch(opc){
      case 0:
          if(codigo_laptop!=""){
            switch(stoi(horario_laptop)){
              case 1:
                horario_laptop = "08am-10am";
                break;
              case 2:
                horario_laptop = "10am-12pm";
                break;
              case 3:
                horario_laptop = "12pm-02pm";
                break;
              case 4:
                horario_laptop = "02pm-04pm";
                break;
              case 5:
                horario_laptop = "04pm-06pm";
                break;
              case 6:
                horario_laptop = "06pm-08pm";
                break;
            }
        change_color(240);
        gotoxy(42, 15);
        cout<<"   Alumno  :"<<users[AdminVerificar::aux].nombre;
        gotoxy(42, 17);
        cout<<"   Laptop  : "<<codigo_laptop;
        gotoxy(42, 19);
        cout<<"   Horario : "<<horario_laptop;
        AdminVerificar::letra = 'B';
        AdminVerificar::confirmar(gestor);
      }else{
        change_color(244);
        gotoxy(42, 17);
        cout<<"  NO TIENE RESERVA ";
        getch();
        gestor.cambiar_ventana(Ventanas::ADMINMAIN);
        break;
      }
        break;
      case 1:
          if(codigo_cubiculo!=""){
            switch(stoi(horario_cubiculo)){
              case 1:
                horario_cubiculo = "08am-10am";
                break;
              case 2:
                horario_cubiculo = "10am-12pm";
                break;
              case 3:
                horario_cubiculo = "12pm-02pm";
                break;
              case 4:
                horario_cubiculo = "02pm-04pm";
                break;
              case 5:
                horario_cubiculo = "04pm-06pm";
                break;
              case 6:
                horario_cubiculo = "06pm-08pm";
                break;
            }
        change_color(240);
        gotoxy(42, 15);
        cout<<"   Alumno   :"<<users[AdminVerificar::aux].nombre;
        gotoxy(42, 17);
        cout<<"   Cubiculo : "<<codigo_cubiculo;
        gotoxy(42, 19);
        cout<<"   Horario  : "<<horario_cubiculo;
        AdminVerificar::letra = 'A';
        AdminVerificar::confirmar(gestor);
        break;
      }else{
        change_color(244);
        gotoxy(42, 17);
        cout<<"  NO TIENE RESERVA ";
        getch();
        gestor.cambiar_ventana(Ventanas::ADMINMAIN);
        break;
      }
    }
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
              if (stoi(data_ultimo[i][2]) == stoi(AdminVerificar::codigo_estudiante)){
                if(AdminVerificar::letra == data_ultimo[i][0][1]){
                  data_ultimo.erase(data_ultimo.begin() + i);
                  break;
                }
              }
          }


          ofstream file_ultimo("reservas_data.csv");
          for(int t=0; t<data_ultimo.size(); t++){
            file_ultimo << data_ultimo[t][0] << "," << data_ultimo[t][1] << "," << data_ultimo[t][2] << endl;
          }

          file_ultimo.close();
          

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
