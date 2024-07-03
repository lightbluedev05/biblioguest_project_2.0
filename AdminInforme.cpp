#include "AdminInforme.h"
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

vector<vector<string>> user;
vector<vector<string>> history_reservas;

using namespace std;

void limpiar() {
  change_color(240);
  gotoxy(12, 4);
  cout<<"                           ";
}


void dibujar_podio() {
  change_color(242);
  gotoxy(21,12); cout<<"██   ██";
  gotoxy(21,13); cout<<"██   ██";
  gotoxy(21,14); cout<<"███████";
  gotoxy(21,15); cout<<"     ██";
  gotoxy(21,16); cout<<"     ██";
  rectangle(19, 9, 15, 17);
  gotoxy(93,15); cout<<"███████";
  gotoxy(93,16); cout<<"██     ";
  gotoxy(93,17); cout<<"███████";
  gotoxy(93,18); cout<<"     ██";
  gotoxy(93,19); cout<<"███████";
  rectangle(19, 6, 87, 20);
  change_color(241);
  gotoxy(39, 6); cout<<"██████ ";
  gotoxy(39, 7); cout<<"     ██";
  gotoxy(39, 8); cout<<" █████ ";
  gotoxy(39, 9); cout<<"██     ";
  gotoxy(39,10); cout<<"███████";
  rectangle(19, 15, 33, 11);
  gotoxy(75, 9); cout<<"██████ ";
  gotoxy(75,10); cout<<"     ██";
  gotoxy(75,11); cout<<"██████ ";
  gotoxy(75,12); cout<<"     ██";
  gotoxy(75,13); cout<<"██████ ";
  rectangle(19, 12, 69, 14);
  change_color(244);
  gotoxy(57,3); cout<<"   ██  ";
  gotoxy(57,4); cout<<"  ███  ";
  gotoxy(57,5); cout<<"   ██  ";
  gotoxy(57,6); cout<<"   ██  ";
  gotoxy(57,7); cout<<"   ██  ";
  rectangle(19, 18, 51, 8);
  change_color(240);
  gotoxy(10,27);
  cout<<"+---------------------------------------------------------------------------------------------------+";
}

void AdminInforme::mostrar(GestorVentanas& gestor) {
    change_color(112);
    system("cls");

    change_color(240);
    rectangle(101, 24, 10, 2);

    change_color(116);
    gotoxy(54, 1);
    cout << "I N F O R M E";
    change_color(240);


    ifstream archivo("datos.txt");
    string line;

    while (getline(archivo, line)) {
      istringstream iss(line);
      vector<string> u;
      string codigo, contra, nombre_completo;

      iss >> codigo >> contra;
      getline(iss, nombre_completo);

      u.push_back(codigo);
      u.push_back(contra);
      u.push_back(nombre_completo);

      user.push_back(u);
    }
    archivo.close();
}

void alumnos_con_mas_reservas() {
    vector<vector<string>> solo_si;
    dibujar_podio();
    ifstream file_5("reservas_history.csv");
    string linea_5;

    history_reservas.clear();

    // Leer datos desde el archivo CSV y almacenar en history_reservas
    while (getline(file_5, linea_5)) {
        vector<string> reservas;
        string reserva;
        stringstream ss(linea_5);

        while (getline(ss, reserva, ',')) {
            reservas.push_back(reserva);
        }

        history_reservas.push_back(reservas);
    }

    file_5.close();

    for (int i = 0; i < history_reservas.size(); i++) {
        if (history_reservas[i][7] == "SI") {
            solo_si.push_back(history_reservas[i]);
        }
    }

    vector<vector<string>> conteo;

    for (int i = 0; i < solo_si.size(); i++) {
        string alumno = solo_si[i][2];
        bool encontrado = false;
        for (int j = 0; j < conteo.size(); j++) {
            if (conteo[j][0] == alumno) {
                int cantidad_reservas = stoi(conteo[j][1]);
                cantidad_reservas++;
                conteo[j][1] = to_string(cantidad_reservas);
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            conteo.push_back({alumno, "1"});
        }
    }

    sort(conteo.begin(), conteo.end(), [](const vector<string>& a, const vector<string>& b) {
        return stoi(a[1]) > stoi(b[1]);
    });

    change_color(240);
    gotoxy(56, 9); cout << "Cant: "<< conteo[0][1];
    change_color(244);
    gotoxy(56, 10); cout << conteo[0][0];
    change_color(240);
    vector<string> palabras;
    palabras.clear();
    for(int i = 1; i < user.size(); i++){
      if(conteo[0][0] == user[i][0]){
        stringstream ss(user[i][2]);
        string palabra;
        while(ss>>palabra){
          palabras.push_back(palabra);
        }
      }
    }
    for(int i = 0; i < palabras.size(); i++){
      gotoxy(56, 11+i); cout << palabras[i];
    }

    change_color(240);
    gotoxy(38, 12); cout <<"Cant: "<< conteo[1][1];
    change_color(244);
    gotoxy(38, 13); cout << conteo[1][0];
    change_color(240);
    palabras.clear();
    for(int i = 1; i < user.size(); i++){
      if(conteo[1][0] == user[i][0]){
        stringstream ss(user[i][2]);
        string palabra;
        while(ss>>palabra){
          palabras.push_back(palabra);
        }
      }
    }
    for(int i = 0; i < palabras.size(); i++){
      gotoxy(38, 14+i); cout << palabras[i];
    }

    change_color(240);
    gotoxy(74, 15); cout << "Cant: "<< conteo[2][1];
    change_color(244);
    gotoxy(74, 16); cout << conteo[2][0];
    change_color(240);
    palabras.clear();
    for(int i = 1; i < user.size(); i++){
      if(conteo[2][0] == user[i][0]){
        stringstream ss(user[i][2]);
        string palabra;
        while(ss>>palabra){
          palabras.push_back(palabra);
        }
      }
    }
    for(int i = 0; i < palabras.size(); i++){
      gotoxy(74, 17+i); cout << palabras[i];
    }

    change_color(240);
    gotoxy(20, 18); cout << "Cant: "<< conteo[3][1];
    change_color(244);
    gotoxy(20, 19); cout << conteo[3][0];
    change_color(240);
    palabras.clear();
    for(int i = 1; i < user.size(); i++){
      if(conteo[3][0] == user[i][0]){
        stringstream ss(user[i][2]);
        string palabra;
        while(ss>>palabra){
          palabras.push_back(palabra);
        }
      }
    }
    for(int i = 0; i < palabras.size(); i++){
      gotoxy(20, 20+i); cout << palabras[i];
    }

    change_color(240);
    gotoxy(92, 21); cout << "Cant: "<< conteo[4][1];
    change_color(244);
    gotoxy(92, 22); cout << conteo[4][0];
    change_color(240);
    palabras.clear();
    for(int i = 1; i < user.size(); i++){
      if(conteo[4][0] == user[i][0]){
        stringstream ss(user[i][2]);
        string palabra;
        while(ss>>palabra){
          palabras.push_back(palabra);
        }
      }
    }
    for(int i = 0; i < 4; i++){
      gotoxy(92, 23+i); cout << palabras[i];
    }
}

void cubiculos_usados() {
    vector<vector<string>> solo_si;

    dibujar_podio();
    ifstream file_5("reservas_history.csv");
    string linea_5;

    history_reservas.clear();

    // Leer datos desde el archivo CSV y almacenar en history_reservas
    while (getline(file_5, linea_5)) {
        vector<string> reservas;
        string reserva;
        stringstream ss(linea_5);

        while (getline(ss, reserva, ',')) {
            reservas.push_back(reserva);
        }

        history_reservas.push_back(reservas);
    }

    file_5.close();
    solo_si.clear();
    for (int i = 0; i < history_reservas.size(); i++) {
        if (history_reservas[i][7] == "SI") {
            solo_si.push_back(history_reservas[i]);
        }
    }

    vector<vector<string>> conteo;
    conteo.clear();
    for (int i = 0; i < solo_si.size(); i++) {
        string codigoCUB = solo_si[i][1];
        bool encontrado = false;
        if(solo_si[i][1][0]=='C'){
          for (int j = 0; j < conteo.size(); j++) {
              if (conteo[j][0] == codigoCUB) {
                  int cantidad_reservas = stoi(conteo[j][1]);
                  cantidad_reservas++;
                  conteo[j][1] = to_string(cantidad_reservas);
                  encontrado = true;
                  break;
              }
          }
          if (!encontrado) {
              conteo.push_back({codigoCUB, "1"});
          }
        }
    }

    sort(conteo.begin(), conteo.end(), [](const vector<string>& a, const vector<string>& b) {
        return stoi(a[1]) > stoi(b[1]);
    });

    change_color(244);
    gotoxy(58, 10); cout << conteo[0][0];
    gotoxy(40, 13); cout << conteo[1][0];
    gotoxy(76, 16); cout << conteo[2][0];
    gotoxy(22, 19); cout << conteo[3][0];
    gotoxy(94, 22); cout << conteo[4][0];
    change_color(240);
    gotoxy(56, 11); cout << "Cant: "<< conteo[0][1];
    gotoxy(38, 14); cout << "Cant: "<< conteo[1][1];
    gotoxy(74, 17); cout << "Cant: "<< conteo[2][1];
    gotoxy(20, 20); cout << "Cant: "<< conteo[3][1];
    gotoxy(92, 23); cout << "Cant: "<< conteo[4][1];    
}

void laptops_usados() {
    vector<vector<string>> solo_si;

    dibujar_podio();
    ifstream file_5("reservas_history.csv");
    string linea_5;

    history_reservas.clear();

    // Leer datos desde el archivo CSV y almacenar en history_reservas
    while (getline(file_5, linea_5)) {
        vector<string> reservas;
        string reserva;
        stringstream ss(linea_5);

        while (getline(ss, reserva, ',')) {
            reservas.push_back(reserva);
        }

        history_reservas.push_back(reservas);
    }

    file_5.close();
    solo_si.clear();
    for (int i = 0; i < history_reservas.size(); i++) {
        if (history_reservas[i][7] == "SI") {
            solo_si.push_back(history_reservas[i]);
        }
    }

    vector<vector<string>> conteo;
    conteo.clear();
    for (int i = 0; i < solo_si.size(); i++) {
        string codigoLAP = solo_si[i][1];
        bool encontrado = false;
        if(solo_si[i][1][0]=='L'){
          for (int j = 0; j < conteo.size(); j++) {
              if (conteo[j][0] == codigoLAP) {
                  int cantidad_reservas = stoi(conteo[j][1]);
                  cantidad_reservas++;
                  conteo[j][1] = to_string(cantidad_reservas);
                  encontrado = true;
                  break;
              }
          }
          if (!encontrado) {
              conteo.push_back({codigoLAP, "1"});
          }
        }
    }

    sort(conteo.begin(), conteo.end(), [](const vector<string>& a, const vector<string>& b) {
        return stoi(a[1]) > stoi(b[1]);
    });

    change_color(244);
    gotoxy(58, 10); cout << conteo[0][0];
    gotoxy(40, 13); cout << conteo[1][0];
    gotoxy(76, 16); cout << conteo[2][0];
    gotoxy(22, 19); cout << conteo[3][0];
    gotoxy(94, 22); cout << conteo[4][0];
    change_color(240);
    gotoxy(56, 11); cout << "Cant: "<< conteo[0][1];
    gotoxy(38, 14); cout << "Cant: "<< conteo[1][1];
    gotoxy(74, 17); cout << "Cant: "<< conteo[2][1];
    gotoxy(20, 20); cout << "Cant: "<< conteo[3][1];
    gotoxy(92, 23); cout << "Cant: "<< conteo[4][1];    
}

string auxhorarionombres(int auxhora) {
    string auxhorario;
    switch(auxhora) {
        case 1:
            auxhorario = "08:00am - 10:00am";
            break;
        case 2:
            auxhorario = "10:00am - 12:00pm";
            break;
        case 3:
            auxhorario = "12:00pm - 02:00pm";
            break;
        case 4:
            auxhorario = "02:00pm - 04:00pm";
            break;
        case 5:
            auxhorario = "04:00pm - 06:00pm";
            break;
        case 6:
            auxhorario = "06:00pm - 08:00pm";
            break;
    }
    return auxhorario;
}

void horario_pico() {
  dibujar_podio();
  vector<vector<int>> laptop;
  vector<vector<int>> cubiculo;
  ifstream file3("laptops_history.csv");
  string linea3;

  laptop.clear();
  while(getline(file3, linea3)){
    vector<int> history;
    string valor;
    stringstream ss3(linea3);

    while(getline(ss3, valor, ',')){
      history.push_back(stoi(valor));
    }
    laptop.push_back(history);
  }
  file3.close();

  //$ CUBICULOS_HISTORY.CSV
  ifstream file33("cubiculos_history.csv");
  string linea33;

  cubiculo.clear();
  while(getline(file33, linea33)){
    vector<int> histori;
    string valo;
    stringstream ss33(linea33);

    while(getline(ss33, valo, ',')){
      histori.push_back(stoi(valo));
    }
    cubiculo.push_back(histori);
  }
  file33.close();

  vector<vector<int>> conteohorario;
  for(int i = 0; i < laptop.size(); i++){
    conteohorario.push_back({i+1, laptop[i][1]+cubiculo[i][1]});
  }
  
  sort(conteohorario.begin(), conteohorario.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });
  
    change_color(244);
    gotoxy(52, 10); cout << auxhorarionombres(conteohorario[0][0]);
    gotoxy(34, 13); cout << auxhorarionombres(conteohorario[1][0]);
    gotoxy(70, 16); cout << auxhorarionombres(conteohorario[2][0]);
    gotoxy(16, 19); cout << auxhorarionombres(conteohorario[3][0]);
    gotoxy(88, 22); cout << auxhorarionombres(conteohorario[4][0]);
    change_color(240);
    gotoxy(56, 11); cout << "Cant: "<< conteohorario[0][1];
    gotoxy(38, 14); cout << "Cant: "<< conteohorario[1][1];
    gotoxy(74, 17); cout << "Cant: "<< conteohorario[2][1];
    gotoxy(20, 20); cout << "Cant: "<< conteohorario[3][1];
    gotoxy(92, 23); cout << "Cant: "<< conteohorario[4][1];    
}

void AdminInforme::dibujar(GestorVentanas& gestor) {
  int opc = 1, tecla = 72;
  while (tecla != 13) {

      if (tecla == 72 && opc > 1) {
          opc--;
      }
      if (tecla == 80 && opc < 4) {
          opc++;
      }

      switch (opc) {
          // Añadir filtro
          case 1:
              limpiar();
              change_color(244);
              gotoxy(12,4);
              cout<<"ALUMNOS CON MAS RESERVAS";
              change_color(240);
              break;
          // Ver tabla
          case 2:
              limpiar();
              change_color(244);
              gotoxy(12,4);   
              cout<<"CUBICULOS USADOS";
              change_color(240);
              break;
          // Salir
          case 3:
              limpiar();
              change_color(244);
              gotoxy(12,4);
              cout<<"LAPTOPS USADOS";
              change_color(240);
              break;
          case 4:
              limpiar();
              change_color(244);
              gotoxy(12,4);
              cout<<"HORARIO PICO";
              change_color(240);
              break;
      }

      switch (opc) {
          case 1:
              alumnos_con_mas_reservas();
              break;
          case 2:
              cubiculos_usados();
              break;
          case 3:
              laptops_usados();
              break;
          case 4:
              horario_pico();
              break;
      }
      tecla = _getch();
  }
}

void AdminInforme::main(GestorVentanas& gestor) {
    AdminInforme::mostrar(gestor);
    AdminInforme::dibujar(gestor);
    getch();
}