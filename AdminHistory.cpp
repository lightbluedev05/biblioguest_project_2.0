#include "AdminHistory.h"
#include "GestorVentanas.h"
#include "functions.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<string>> AdminHistory::reservas_historial;
vector<vector<string>> AdminHistory::filtro;
vector<vector<string>> AdminHistory::aux;
int AdminHistory::op;
string AdminHistory::buscar;
int AdminHistory::auxpase;
int AdminHistory::aux2;


bool filtro_valido(const string& filtro) {
    set<string> filtros_validos;

    if (AdminHistory::op == 3) {
        filtros_validos = {"1", "2", "3", "4", "5", "6"};
    } else if (AdminHistory::op == 4) {
        filtros_validos = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
    } else if (AdminHistory::op == 5) {
        filtros_validos = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
    } else if (AdminHistory::op == 7) {
        filtros_validos = {"SI", "NO", "si", "no", "Si", "No", "sI", "nO"};
    } else {
        return false;
    }

  return find(filtros_validos.begin(), filtros_validos.end(), filtro) != filtros_validos.end();
}

void AdminHistory::mostrar(GestorVentanas& gestor) {
    change_color(112);
    system("cls");

    change_color(240);
    rectangle(100, 24, 10, 2);

    button(13, 1, 20, 7, "COD R");
    button(15, 1, 40, 7, "COD L/C");
    button(18, 1, 62, 7, "COD ALUMNO");
    button(15, 1, 85, 7, "HORARIO");
    button(11, 1, 21, 10, "DIA");
    button(11, 1, 42,10, "MES");
    button(11, 1, 65,10, "ANO");
    button(9, 1, 88, 10, "USO");
    button(18, 1, 34, 4, "ANADIR FILTRO");
    button(16, 1, 54, 4, "VER TABLA");
    button(12, 1, 72, 4, "SALIR");
    button(9, 1, 86, 4, "EXCEL");
    button(9, 1, 97, 4, "RESET");

    change_color(244);
    gotoxy(49, 3);
    cout << "HISTORIAL DE RESERVAS";
    change_color(241);
    rectangle(10, 1, 22, 4);
    button(13, 1, 12, 14, "COD R");
    button(15, 1, 24, 14, "COD L/C");
    button(18, 1, 38, 14, "COD ALUMNO");
    button(15, 1, 55, 14, "HORARIO");
    button(11, 1, 69, 14, "DIA");
    button(11, 1, 79, 14, "MES");
    button(11, 1, 89, 14, "ANO");
    button(9, 1, 99, 14, "USO");
    change_color(240);
    buscar_salir_ver(gestor);
}

void AdminHistory::dibujar_tabla(GestorVentanas& gestor) {
    AdminHistory::aux2=-17;
    int opc = 0, tecla = 77;
    while (tecla != 13) {
        if (tecla == 75 && opc > 1) {
            opc--;
            AdminHistory::aux2 = AdminHistory::aux2 - 11;
        }
        if (tecla == 77 && opc < (round(AdminHistory::filtro.size()/10))+1) {
            opc++;
            AdminHistory::aux2 = AdminHistory::aux2 + 11;
        }

        if(opc == 1){
          change_color(112);
          system("cls");

          change_color(240);
          rectangle(100, 24, 10, 2);

          button(13, 1, 20, 7, "COD R");
          button(15, 1, 40, 7, "COD L/C");
          button(18, 1, 62, 7, "COD ALUMNO");
          button(15, 1, 85, 7, "HORARIO");
          button(11, 1, 21, 10, "DIA");
          button(11, 1, 42,10, "MES");
          button(11, 1, 65,10, "ANO");
          button(9, 1, 88, 10, "USO");
          button(18, 1, 34, 4, "ANADIR FILTRO");
          button(16, 1, 54, 4, "VER TABLA");
          button(12, 1, 72, 4, "SALIR");
          button(9, 1, 86, 4, "EXCEL");
          button(9, 1, 97, 4, "RESET");

          change_color(244);
          gotoxy(49, 3);
          cout << "HISTORIAL DE RESERVAS";
          change_color(241);
          rectangle(10, 1, 22, 4);
          button(13, 1, 12, 14, "COD R");
          button(15, 1, 24, 14, "COD L/C");
          button(18, 1, 38, 14, "COD ALUMNO");
          button(15, 1, 55, 14, "HORARIO");
          button(11, 1, 69, 14, "DIA");
          button(11, 1, 79, 14, "MES");
          button(11, 1, 89, 14, "ANO");
          button(9, 1, 99, 14, "USO");
          change_color(240);
          int aux = 16;
          string hora = "";
          int auxp;
          if(AdminHistory::filtro.size() <5){
            auxp = AdminHistory::filtro.size();
          }else{
            auxp = 5;
          }
          for (int i = 0; i < auxp; i++) {
              switch (stoi(AdminHistory::filtro[i][3])) {
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
              button(13, 1, 12, aux, AdminHistory::filtro[i][0]);
              button(15, 1, 24, aux, AdminHistory::filtro[i][1]);
              button(18, 1, 38, aux, AdminHistory::filtro[i][2]);
              button(15, 1, 55, aux, hora);
              button(11, 1, 69, aux, AdminHistory::filtro[i][4]);
              button(11, 1, 79, aux, AdminHistory::filtro[i][5]);
              button(11, 1, 89, aux, AdminHistory::filtro[i][6]);
              button(9, 1, 99, aux, AdminHistory::filtro[i][7]);
              aux += 2;
          }
          gotoxy(70,27);
          change_color(241);
          cout<<"Pagina-"<<opc<<"-de-"<<(round(AdminHistory::filtro.size()/10)+1);
          change_color(240);
        } else{
          change_color(112);
          system("cls");

          change_color(240);
          rectangle(100, 25, 10, 1);
          change_color(241);
          button(13, 1, 12, 2, "COD R");
          button(15, 1, 24, 2, "COD L/C");
          button(18, 1, 38, 2, "COD ALUMNO");
          button(15, 1, 55, 2, "HORARIO");
          button(11, 1, 69, 2, "DIA");
          button(11, 1, 79, 2, "MES");
          button(11, 1, 89, 2, "ANO");
          button(9, 1, 99, 2, "USO");
          gotoxy(70,27);
          cout<<"Pagina-"<<opc<<"-de-"<<(round(AdminHistory::filtro.size()/10)+1);
          change_color(240);

          change_color(244);
          gotoxy(49, 1);
          cout << "HISTORIAL-DE-RESERVAS";
          change_color(240);
          int aux = 4;
          string hora = "";
          if(opc==((round(AdminHistory::filtro.size()/10))+1)){
            AdminHistory::auxpase = AdminHistory::filtro.size();
          }else{
            AdminHistory::auxpase = AdminHistory::aux2 + 11;
          }
          for (int i = AdminHistory::aux2; i < AdminHistory::auxpase; i++) {
              switch (stoi(AdminHistory::filtro[i][3])) {
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
              button(13, 1, 12, aux, AdminHistory::filtro[i][0]);
              button(15, 1, 24, aux, AdminHistory::filtro[i][1]);
              button(18, 1, 38, aux, AdminHistory::filtro[i][2]);
              button(15, 1, 55, aux, hora);
              button(11, 1, 69, aux, AdminHistory::filtro[i][4]);
              button(11, 1, 79, aux, AdminHistory::filtro[i][5]);
              button(11, 1, 89, aux, AdminHistory::filtro[i][6]);
              button(9, 1, 99, aux, AdminHistory::filtro[i][7]);
              aux += 2;
          }
        }

        tecla = _getch();
    }
  mostrar(gestor);
}

void AdminHistory::jalar_datos(GestorVentanas& gestor) {
    ifstream file_5("reservas_history.csv");
    string linea_5;

    AdminHistory::reservas_historial.clear();

    // Leer datos desde el archivo CSV y almacenar en reservas_historial
    while (getline(file_5, linea_5)) {
        vector<string> reservas;
        string reserva;
        stringstream ss(linea_5);

        while (getline(ss, reserva, ',')) {
            reservas.push_back(reserva);
        }

        AdminHistory::reservas_historial.push_back(reservas);
    }

    file_5.close();

    AdminHistory::filtro = AdminHistory::reservas_historial;
}

void AdminHistory::buscar_salir_ver(GestorVentanas& gestor) {
    int opc = 0, tecla = 77;
    while (tecla != 13) {

        if (tecla == 75 && opc > 1) {
            opc--;
        }
        if (tecla == 77 && opc < 5) {
            opc++;
        }

        switch (opc) {
            // Añadir filtro
            case 1:
                change_color(244);
                button(18, 1, 34, 4, "ANADIR FILTRO");
                change_color(240);
                button(16, 1, 54, 4, "VER TABLA");
                button(12, 1, 72, 4, "SALIR");
                button(9, 1, 86, 4, "EXCEL");
                button(9, 1, 97, 4, "RESET");
                break;
            // Ver tabla
            case 2:
                change_color(240);
                button(18, 1, 34, 4, "ANADIR FILTRO");
                change_color(244);
                button(16, 1, 54, 4, "VER TABLA");
                change_color(240);
                button(12, 1, 72, 4, "SALIR");
                button(9, 1, 86, 4, "EXCEL");
                button(9, 1, 97, 4, "RESET");
                break;
            // Salir
            case 3:
                change_color(240);
                button(18, 1, 34, 4, "ANADIR FILTRO");
                button(16, 1, 54, 4, "VER TABLA");
                change_color(244);
                button(12, 1, 72, 4, "SALIR");
                change_color(240);
                button(9, 1, 86, 4, "EXCEL");
                button(9, 1, 97, 4, "RESET");
                break;
            case 4:
                change_color(240);
                button(18, 1, 34, 4, "ANADIR FILTRO");
                button(16, 1, 54, 4, "VER TABLA");
                button(12, 1, 72, 4, "SALIR");
                change_color(244);
                button(9, 1, 86, 4, "EXCEL");
                change_color(240);
                button(9, 1, 97, 4, "RESET");
                break;
            case 5:
                change_color(240);
                button(18, 1, 34, 4, "ANADIR FILTRO");
                button(16, 1, 54, 4, "VER TABLA");
                button(12, 1, 72, 4, "SALIR");
                button(9, 1, 86, 4, "EXCEL");
                change_color(244);
                button(9, 1, 97, 4, "RESET");
                change_color(240);
                break;
        }

        tecla = _getch();
    }
    std::string filePath;
    std::string command;
    int result;
    switch (opc) {
        case 1:
            elegir_opcion(gestor);
            break;
        case 2:
            dibujar_tabla(gestor);
            break;
        case 3:
            exit(0);
            break;
        case 4:{
            ofstream file_3("reservas_filtro.csv");

            for(int i = 0; i < AdminHistory::filtro.size(); i++) {
              for(int j = 0; j < AdminHistory::filtro[i].size(); j++) {
                file_3<<AdminHistory::filtro[i][j];
                if(j < AdminHistory::filtro[i].size() - 1) {
                    file_3<<",";
                }
              }
              file_3<<"\n";
            }
            file_3.close();

            change_color(240);
            gotoxy(11, 13);
            cout<<"                                                                                                  ";
            change_color(250);
            gotoxy(45,13);
            cout<<"Abriendo excel...";
            change_color(240);
            //gestor.cambiar_ventana(Ventanas::ADMINSTATIC);
            filePath = "Filtro.xlsx";

            // Comando para abrir Excel con el archivo especificado
            command = "start excel \"" + filePath + "\"";

            // Ejecutar el comando
            result = std::system(command.c_str());
            mostrar(gestor);
            break;
        }
        case 5:
            jalar_datos(gestor);
            break;
    }
}

void AdminHistory::aplicar_filtro(GestorVentanas& gestor) {
  int cont = 0;
  if(AdminHistory::op==0 || AdminHistory::op==1 || AdminHistory::op==2 || AdminHistory::op==6){
    gotoxy(24,5);
    show_cursor();
    cin>>AdminHistory::buscar;    
  }else{
    do{
      cont++;
      if(cont >1){
        change_color(244);
        gotoxy(11, 5);
        cout << "INCORRECTO";
        change_color(240);
        gotoxy(24,5);
        cout<<"      ";
      }
      gotoxy(24,5);
      show_cursor();
      cin>>AdminHistory::buscar;
    }while(!filtro_valido(AdminHistory::buscar));
  }
  hide_cursor();
  change_color(250);
  gotoxy(11, 5);
  cout << " CORRECTO ";
  AdminHistory::aux.clear();
  for (int i = 0; i < AdminHistory::filtro.size(); i++) {
    if(AdminHistory::filtro[i][AdminHistory::op] == AdminHistory::buscar){
      aux.push_back(AdminHistory::filtro[i]);
    }
  }
  AdminHistory::filtro = AdminHistory::aux;

  mostrar(gestor);
}

void AdminHistory::elegir_opcion(GestorVentanas& gestor) {
  int aux_x=0, aux_y=0, tecla=75;

  while(tecla!=13){
    switch (tecla){
      case 75:
        if(aux_x>0){
          aux_x--;
        }
        break;

      case 77:
        if(aux_x<3){
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

    if(aux_x==0 && aux_y==0){
      change_color(244);
      button(13, 1, 20, 7, "COD R");
      change_color(240);
      button(15, 1, 40, 7, "COD L/C");
      button(18, 1, 62, 7, "COD ALUMNO");
      button(15, 1, 85, 7, "HORARIO");
      button(11, 1, 21, 10, "DIA");
      button(11, 1, 42,10, "MES");
      button(11, 1, 65, 10, "ANO");
      button(9, 1, 88, 10, "USO");
      change_color(240);
      gotoxy(11, 13);
      cout<<"                                                                                                  ";
      change_color(250);
      gotoxy(45,13);
      cout<<"Digite el codigo de la reserva";
      change_color(240);
      AdminHistory::op = 0;       
    }

    if(aux_x==1 && aux_y==0){
      change_color(240);
      button(13, 1, 20, 7, "COD R");
      change_color(244);
      button(15, 1, 40, 7, "COD L/C");
      change_color(240);
      button(18, 1, 62, 7, "COD ALUMNO");
      button(15, 1, 85, 7, "HORARIO");
      button(11, 1, 21, 10, "DIA");
      button(11, 1, 42, 10, "MES");
      button(11, 1, 65, 10, "ANO");
      button(9, 1, 88, 10, "USO");
      change_color(240);
      gotoxy(11, 13);
      cout<<"                                                                                                  ";
      change_color(250);
      gotoxy(41,13);
      cout<<"Digite el codigo de la Laptop o Cubiculo";
      change_color(240);
      AdminHistory::op = 1;       
    }

    if(aux_x==2 && aux_y==0){
      change_color(240);
      button(13, 1, 20, 7, "COD R");
      button(15, 1, 40, 7, "COD L/C");
      change_color(244);
      button(18, 1, 62, 7, "COD ALUMNO");
      change_color(240);
      button(15, 1, 85, 7, "HORARIO");
      button(11, 1, 21, 10, "DIA");
      button(11, 1, 42, 10, "MES");
      button(11, 1, 65, 10, "ANO");
      button(9, 1, 88, 10, "USO");
      change_color(240);
      gotoxy(11, 13);
      cout<<"                                                                                                  ";
      change_color(250);
      gotoxy(45,13);
      cout<<"Digite el codigo del alumno";
      change_color(240);
      AdminHistory::op = 2;       
    }

    if(aux_x==3 && aux_y==0){
      change_color(240);
      button(13, 1, 20, 7, "COD R");
      button(15, 1, 40, 7, "COD L/C");
      button(18, 1, 62, 7, "COD ALUMNO");
      change_color(244);
      button(15, 1, 85, 7, "HORARIO");
      change_color(240);
      button(11, 1, 21, 10, "DIA");
      button(11, 1, 42, 10, "MES");
      button(11, 1, 65, 10, "ANO");
      button(9, 1, 88, 10, "USO");
      change_color(240);
      gotoxy(11, 13);
      cout<<"                                                                                                  ";
      change_color(250);
      gotoxy(11,13);
      cout<<"1: 8:00-10:00 / 2: 10:00-12:00 / 3: 12:00-14:00 / 4: 14:00-16:00 / 5: 16:00-18:00 / 6: 18:00-20:00";
      change_color(240);
      AdminHistory::op = 3;       
    }

    if(aux_x==0 && aux_y==1){
      change_color(240);
      button(13, 1, 20, 7, "COD R");
      button(15, 1, 40, 7, "COD L/C");
      button(18, 1, 62, 7, "COD ALUMNO");
      button(15, 1, 85, 7, "HORARIO");
      change_color(244);
      button(11, 1, 21, 10, "DIA");
      change_color(240);
      button(11, 1, 42, 10, "MES");
      button(11, 1, 65, 10, "ANO");
      button(9, 1, 88, 10, "USO");
      change_color(240);
      gotoxy(11, 13);
      cout<<"                                                                                                  ";
      change_color(250);
      gotoxy(47,13);
      cout<<"Digite el numero del dia";
      change_color(240);
      AdminHistory::op = 4;      
    }

    if(aux_x==1 && aux_y==1){
      change_color(240);
      button(13, 1, 20, 7, "COD R");
      button(15, 1, 40, 7, "COD L/C");
      button(18, 1, 62, 7, "COD ALUMNO");
      button(15, 1, 85, 7, "HORARIO");
      button(11, 1, 21, 10, "DIA");
      change_color(244);
      button(11, 1, 42, 10, "MES");
      change_color(240);
      button(11, 1, 65, 10, "ANO");
      button(9, 1, 88, 10, "USO");
      change_color(240);
      gotoxy(11, 13);
      cout<<"                                                                                                  ";
      change_color(250);
      gotoxy(47,13);
      cout<<"Digite el numero del mes";
      change_color(240);
      AdminHistory::op = 5;      
    }

    if(aux_x==2 && aux_y==1){
      change_color(240);
      button(13, 1, 20, 7, "COD R");
      button(15, 1, 40, 7, "COD L/C");
      button(18, 1, 62, 7, "COD ALUMNO");
      button(15, 1, 85, 7, "HORARIO");
      button(11, 1, 21, 10, "DIA");
      button(11, 1, 42, 10, "MES");
      change_color(244);
      button(11, 1, 65, 10, "ANO");
      change_color(240);
      button(9, 1, 88, 10, "USO");
      change_color(240);
      gotoxy(11, 13);
      cout<<"                                                                                                  ";
      change_color(250);
      gotoxy(47,13);
      cout<<"Digite el numero del ano";
      change_color(240);
      AdminHistory::op = 6;     
    }

    if(aux_x==3 && aux_y==1){
      change_color(240);
      button(13, 1, 20, 7, "COD R");
      button(15, 1, 40, 7, "COD L/C");
      button(18, 1, 62, 7, "COD ALUMNO");
      button(15, 1, 85, 7, "HORARIO");
      button(11, 1, 21, 10, "DIA");
      button(11, 1, 42, 10, "MES");
      button(11, 1, 65, 10, "ANO");
      change_color(244);
      button(9, 1, 88, 10, "USO");
      change_color(240);
      gotoxy(11, 13);
      cout<<"                                                                                                  ";
      change_color(250);
      gotoxy(53,13);
      cout<<"Digite SI o NO";
      change_color(240);
      AdminHistory::op = 7;    
    }

		tecla = _getch();
  }
  aplicar_filtro(gestor);
}

void AdminHistory::main(GestorVentanas& gestor) {
    AdminHistory::jalar_datos(gestor);
    AdminHistory::mostrar(gestor);
    getch();
}