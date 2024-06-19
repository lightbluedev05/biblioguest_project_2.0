#include "AdminHistory.h"
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

vector<vector<string>> AdminHistory::reservas_historial;

void AdminHistory::mostrar(GestorVentanas& gestor){
  change_color(112);
  system("cls");

  change_color(240);
  rectangle(100, 24, 10, 2);

  button(13, 1, 20, 5, "COD R");
  button(15, 1, 40, 5, "COD L/C");
  button(18, 1, 62, 5, "COD ALUMNO");
  button(15, 1, 85, 5, "HORARIO");
  button(11, 1, 21, 8, "DIA");
  button(11, 1, 42, 8, "MES");
  button(11, 1, 65, 8, "ANO");
  button(9, 1, 88, 8, "USO");

  change_color(244);
  gotoxy(49,3);
  cout<<"HISTORIAL DE RESERVAS";
  change_color(241);
  button(13, 1, 12, 12, "COD R");
  button(15, 1, 24, 12, "COD L/C");
  button(18, 1, 38, 12, "COD ALUMNO");
  button(15, 1, 55, 12, "HORARIO");
  button(11, 1, 69, 12, "DIA");
  button(11, 1, 79, 12, "MES");
  button(11, 1, 89, 12, "ANO");
  button(9, 1, 99, 12, "USO");
  change_color(240);
  gotoxy(10, 27);
  cout<<"|                                                                                                  |";
}

void AdminHistory::dibujar_tabla(GestorVentanas& gestor) {
    change_color(240);
    ifstream file_5("reservas_history.csv");
    string linea_5;

    AdminHistory::reservas_historial.clear(); // Usar AdminHistory::reservas_historial en lugar de LaptopReserva::reservas_historial

    // Leer datos desde el archivo CSV y almacenar en reservas_historial
    while (getline(file_5, linea_5)) {
        vector<string> reservas = {};
        string reserva = "";
        stringstream ss(linea_5);

        while (getline(ss, reserva, ',')) {
            reservas.push_back(reserva);
        }

        AdminHistory::reservas_historial.push_back(reservas);
    }

    file_5.close();

    int aux = 14;
    int aumento = 27;
    string hora = "";
    for (int i = 0; i < AdminHistory::reservas_historial.size(); i++) {
        switch (stoi(AdminHistory::reservas_historial[i][3])) {
            case 1:
                hora = "08am-10am";
                break;
            case 2:
                hora = "10am-12pm";
                break;
            case 3:
                hora = "12pm-02pm";
                break;
            case 4:
                hora = "02pm-04pm";
                break;
            case 5:
                hora = "04pm-06pm";
                break;
            case 6:
                hora = "06pm-08pm";
                break;
        }

      if(i>5){
        for(int j=0; j<2; j++){
          change_color(112);
          change_color(240);
          gotoxy(10, aumento);
          cout<<"| ";
          gotoxy(108, aumento);
          cout<<" |";
          aumento ++;
        }
      }
        button(13, 1, 12, aux, AdminHistory::reservas_historial[i][0]);
        button(15, 1, 24, aux, AdminHistory::reservas_historial[i][1]);
        button(18, 1, 38, aux, AdminHistory::reservas_historial[i][2]);
        button(15, 1, 55, aux, hora);
        button(11, 1, 69, aux, AdminHistory::reservas_historial[i][4]);
        button(11, 1, 79, aux, AdminHistory::reservas_historial[i][5]);
        button(11, 1, 89, aux, AdminHistory::reservas_historial[i][6]);
        button(9, 1, 99, aux, AdminHistory::reservas_historial[i][7]);
        aux += 2;
    }
  gotoxy(10, aumento);
  cout<<"|                                                                                                  |"; 
  gotoxy(10, aumento+1);
  cout<<"+--------------------------------------------------------------------------------------------------+";  
}

void AdminHistory::main(GestorVentanas& gestor){
  AdminHistory::mostrar(gestor);
  AdminHistory::dibujar_tabla(gestor);
  getch();
}