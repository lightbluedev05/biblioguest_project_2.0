#include "GestorVentanas.h"
#include "LaptopReserva.h"
#include "functions.h"

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string LaptopReserva::codigo_laptop;
string LaptopReserva::horario_laptop;
vector<vector<string>> LaptopReserva::horarios_data;
vector<vector<string>> LaptopReserva::reservas_data;
vector<vector<int>> LaptopReserva::historial;

void LaptopReserva::mostrar(){
  change_color(112);
  system("cls");

  //$ RECTANGULO VENTANA
  change_color(240);
  rectangle(70, 21, 25, 3);

  //$ ENCABEZADO
  change_color(241);
  gotoxy(50, 5);
  cout<<"RESERVA DE LAPTOP";

  change_color(240);
  gotoxy(40, 8);
  cout<<"CODIGO DEL LAPTOP: #";
  rectangle(15,1,60,7);

  gotoxy(54, 11);
  cout<<"HORARIOS";

  //$ RECTANGULOS DE HORARIOS Y OPCIONES
  rectangle(15, 1, 33, 13);
  rectangle(15, 1, 53, 13);
  rectangle(15, 1, 73, 13);
  rectangle(15, 1, 33, 17);
  rectangle(15, 1, 53, 17);
  rectangle(15, 1, 73, 17);

  rectangle(15, 1, 43, 21);
  rectangle(15, 1, 63, 21);

  //$ TEXTO HORARIOS Y OPCIONES
  gotoxy(36, 14);
  cout<<"08am-10am";
  gotoxy(56, 14);
  cout<<"10am-12pm";
  gotoxy(76, 14);
  cout<<"12pm-02pm";
  gotoxy(36, 18);
  cout<<"02pm-04pm";
  gotoxy(56, 18);
  cout<<"04pm-06pm";
  gotoxy(76, 18);
  cout<<"06pm-08pm";

  gotoxy(47, 22);
  cout<<"RESERVAR";
  gotoxy(68, 22);
  cout<<"SALIR";

}

void LaptopReserva::conseguir_data(){
  //$ HORARIOS_DATA.CSV
  ifstream file("horarios_data.csv");
  string linea;

  LaptopReserva::horarios_data.clear();

  while(getline(file, linea)){
    vector<string> horarios={};
    string horario="";
    stringstream ss(linea);

    while(getline(ss, horario, ',')){
      horarios.push_back(horario);
    }
    LaptopReserva::horarios_data.push_back(horarios);
  }
  file.close();

  //$ RESERVAS_DATA.CSV
  ifstream file2("reservas_data.csv");
  string linea2;

  LaptopReserva::reservas_data.clear();
  while(getline(file2, linea2)){
    vector<string> reservas={};
    string reserva="";
    stringstream ss2(linea2);

    while(getline(ss2, reserva, ',')){
      reservas.push_back(reserva);
    }
    LaptopReserva::reservas_data.push_back(reservas);
  }
  file2.close();

  //$ LAPTOPS_HISTORY.CSV
  ifstream file3("laptops_history.csv");
  string linea3;

  LaptopReserva::historial.clear();
  while(getline(file3, linea3)){
    vector<int> history;
    string valor;
    stringstream ss3(linea3);

    while(getline(ss3, valor, ',')){
      history.push_back(stoi(valor));
    }
    LaptopReserva::historial.push_back(history);
  }
  file3.close();
}

void LaptopReserva::ingresar_datos(GestorVentanas& gestor){
  show_cursor();

  //$ INGRESO DEL CODIGO
  bool valido = false;
  int fallidos = 0;

  while(!valido){
    gotoxy(61, 8);
    cout<<"             ";
    gotoxy(61, 8);
    cin>>LaptopReserva::codigo_laptop;

    for(int i=0; i<20; i++){
      if(LaptopReserva::codigo_laptop==LaptopReserva::horarios_data[i][0]){
        valido = true;
        break;
      }
    }
    gotoxy(77, 8);
    if(!valido){
      fallidos += 1;
      cout<<"NO VALIDO";
    } else {
      cout<<"         ";
    }
    if(fallidos>2){
      gotoxy(77, 7);
      cout<<"Presione Enter";
      gotoxy(77, 8);
      cout<<"para volver";
      gotoxy(77, 9);
      cout<<"al Menu...";
      getch();
      gestor.cambiar_ventana(Ventanas::LAPTOPMAIN);
      break;
    }
  }

  //$ INGRESO DEL HORARIO
  if(valido){
    hide_cursor();
    int opcion_x=0, opcion_y=0;
    int tecla=75, horario;

    while(tecla!=13){
      switch(tecla){
        case 75:
          if(opcion_x>0){
            opcion_x--;
          }
          break;
        case 77:
          if(opcion_x<2){
            opcion_x++;
          }
          break;
        case 72:
          if(opcion_y>0){
            opcion_y--;
          }
          break;
        case 80:
          if(opcion_y<1){
            opcion_y++;
          }
          break;
      }

      //$ PINTADO DEL HORARIO
      if(opcion_x==0 && opcion_y==0){change_color(113); LaptopReserva::horario_laptop = "1";}
      rectangle(15, 1, 33, 13);
      gotoxy(36, 14);
      cout<<"08am-10am";
      change_color(240);

      if(opcion_x==1 && opcion_y==0){change_color(113); LaptopReserva::horario_laptop = "2";}
      rectangle(15, 1, 53, 13);
      gotoxy(56, 14);
      cout<<"10am-12pm";
      change_color(240);

      if(opcion_x==2 && opcion_y==0){change_color(113); LaptopReserva::horario_laptop = "3";}
      rectangle(15, 1, 73, 13);
      gotoxy(76, 14);
      cout<<"12pm-02pm";
      change_color(240);

      if(opcion_x==0 && opcion_y==1){change_color(113); LaptopReserva::horario_laptop = "4";}
      rectangle(15, 1, 33, 17);
      gotoxy(36, 18);
      cout<<"02pm-04pm";
      change_color(240);

      if(opcion_x==1 && opcion_y==1){change_color(113); LaptopReserva::horario_laptop = "5";}
      rectangle(15, 1, 53, 17);
      gotoxy(56, 18);
      cout<<"04pm-06pm";
      change_color(240);

      if(opcion_x==2 && opcion_y==1){change_color(113); LaptopReserva::horario_laptop = "6";}
      rectangle(15, 1, 73, 17);
      gotoxy(76, 18);
      cout<<"06pm-08pm";
      change_color(240);

      tecla=_getch();
    }
  }

  //$ CONFIRMACION DE RESERVA
  if(valido){
    int tecla=75;
    int aux;

    while(tecla!=13){
      
      if(tecla==75){change_color(113); aux=0;}
      rectangle(15, 1, 43, 21);
      gotoxy(47, 22);
      cout<<"RESERVAR";
      change_color(240);

      if(tecla==77){change_color(113); aux=1;}
      rectangle(15, 1, 63, 21);
      gotoxy(68, 22);
      cout<<"SALIR";
      change_color(240);

      tecla=_getch();
    }

    switch(aux){
      case 0:
        LaptopReserva::comprobacion_de_datos(gestor);
        break;
      case 1:
        gestor.cambiar_ventana(Ventanas::LAPTOPMAIN);
        break;
    }
  }
}

void LaptopReserva::comprobacion_de_datos(GestorVentanas& gestor){
  vector<vector<string>> data = LaptopReserva::horarios_data;
  vector<vector<string>> r_data = LaptopReserva::reservas_data;
  int busqueda=0, horario_aux, linea;

  for(int i=0; i<r_data.size(); i++){
    if(r_data[i][2]==gestor.codigo && r_data[i][0][1]=='B'){
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

    // Establecer los horarios límite según el horario seleccionado
    switch (stoi(LaptopReserva::horario_laptop)) {
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
      if(data[i][0]==LaptopReserva::codigo_laptop){
        linea = i;
        horario_aux = stoi(LaptopReserva::horario_laptop);
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
      cout<<"NO SE HA ENCONTRADO ESTE CODIGO DE LAPTOP";
      break;
    case 1:
      gotoxy(45, 12);
      cout<<"ESTE HORARIO YA ESTA RESERVADO";
      change_color(241);
      gotoxy(41,13);
      cout<<"PRESIONE CUALQUIER TECLA PARA CONTINUAR";
      change_color(240);
      gestor.cambiar_ventana(Ventanas::LAPTOPMAIN);
      break;
    case 2:
      ejecutar_reserva(gestor, linea, horario_aux);
      gotoxy(45, 12);
      cout<<"RESERVA EJECUTADA CON EXITO :)";
      change_color(241);
      gotoxy(41,13);
      cout<<"PRESIONE CUALQUIER TECLA PARA CONTINUAR";
      change_color(240);
      gestor.cambiar_ventana(Ventanas::LAPTOPMAIN);
      break;
    case 3:
      gotoxy(44, 12);
      cout<<"YA HAS EJECUTADO UNA RESERVA HOY";
      change_color(241);
      gotoxy(41,13);
      cout<<"PRESIONE CUALQUIER TECLA PARA CONTINUAR";
      change_color(240);
      gestor.cambiar_ventana(Ventanas::LAPTOPMAIN);
      break;
    case 4:
      gotoxy(25, 10);
      cout<<"--------¡¡¡¡¡¡¡¡¡¡¡¡ESTAS FUERA DE HORA!!!!!!!!!!!!!!--------";
      change_color(241);
      gotoxy(34,11);
      cout<<"REVISA LOS HORARIOS DISPONIBLES EN LA LISTA DE CUBICULOS";
      change_color(240);
      gestor.cambiar_ventana(Ventanas::LAPTOPMAIN);
      break;
  }

  getch();
}

void LaptopReserva::ejecutar_reserva(GestorVentanas& gestor, int laptop, int horario){
  ofstream file("horarios_data.csv");
  
  vector<vector<string>> data = LaptopReserva::horarios_data;

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
  file_2<<LaptopReserva::codigo_laptop<<","<<LaptopReserva::horario_laptop<<","<<gestor.codigo<<"\n";
  file_2.close();

  for(int i = 0; i < LaptopReserva::historial.size(); i++) {
    int aux = stoi(LaptopReserva::horario_laptop);
      if(LaptopReserva::historial[i][0] == aux) {
          LaptopReserva::historial[i][1]++;
          break;
      }
  }

  ofstream file_3("laptops_history.csv");

  for(int i = 0; i < LaptopReserva::historial.size(); i++) {
    for(int j = 0; j < LaptopReserva::historial[i].size(); j++) {
      file_3<<LaptopReserva::historial[i][j];
      if(j < LaptopReserva::historial[i].size() - 1) {
          file_3<<",";
      }
    }
    file_3<<"\n";
  }
  file_3.close();
}

void LaptopReserva::main(GestorVentanas& gestor){
  LaptopReserva::mostrar();
  LaptopReserva::conseguir_data();
  LaptopReserva::ingresar_datos(gestor);
}