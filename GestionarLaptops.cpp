#include "GestionarLaptops.h"
#include <iostream>
#include <conio.h>
#include "functions.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void GestionarLaptops::mostrar() {
  change_color(112);
  system("cls");

  change_color(240);
  rectangle(83, 18, 19, 4);

  change_color(244);
  gotoxy(52, 6);
  cout<<"GESTIONAR LAPTOPS";

  change_color(241);
  gotoxy(32, 21);
  cout<<"UTILIZE LAS FLECHAS -> Y <- PARA SELECCIONAR LAS OPCIONES";
}

void GestionarLaptops::cantidad_laptops(){

  change_color(240);
  system("cls");

  gotoxy(26, 10);
  cout<<"Esta operacion elimina todas las laptops existentes y te permite crear";
  gotoxy(27, 11);
  cout<<"nuevas desde cero... si solo desea agregar dirijase a ANADIR LAPTOP";

  change_color(241);
  gotoxy(36, 13);
  cout<<"SI DA 'ACCEDER' LAS LAPTOPS ACTUALES SE BORRARAN";
  change_color(240);

  int tecla=75, opc;
  while(tecla!=13){
    if(tecla==75){
      change_color(241);
      button(15, 1, 40, 15, "ACCEDER");
      change_color(240);
      button(15, 1, 60, 15, "ATRAS");
      opc=1;
    } else if (tecla==77){
      button(15, 1, 40, 15, "ACCEDER");
      change_color(241);
      button(15, 1, 60, 15, "ATRAS");
      change_color(240);
      opc=2;
    }
    tecla=_getch();
  }

  if(opc==1){
    //$ HORARIOS_DATA.CSV
    vector<vector<string>> horarios_data;
    ifstream file("horarios_data.csv");
    string linea;

    horarios_data.clear();

    while(getline(file, linea)){
      vector<string> horarios={};
      string horario="";
      stringstream ss(linea);

      while(getline(ss, horario, ',')){
        horarios.push_back(horario);
      }
      if(horarios[0][0]!='L'){
        horarios_data.push_back(horarios);
      }
    }
    file.close();

    //$ PINTADO DE VENTANA
    show_cursor();
    change_color(112);
    system("cls");

    change_color(240);
    rectangle(83, 18, 19, 4);

    change_color(244);
    gotoxy(47, 6);
    cout<<"REINICIO DE INVENTARIO DE LAPTOPS";
    change_color(240);

    rectangle(6, 1, 64, 8);
    gotoxy(48, 9);
    cout<<"Nro de laptops:";

    gotoxy(52, 12);
    cout<<"Elige modo de creacion...";

    button(14, 1, 47, 14, "Automatico");
    button(14, 1, 64, 14, "Manual");

    change_color(241);  
    gotoxy(23,20);
    cout<<"'AUTOMATICO' hara que las laptops inicien desde L0001, sin especificaciones";
    gotoxy(40,21);
    cout<<"'MANUAL' te permitira especificar para cada laptop";
    change_color(240);

    //$ CANTIDAD DE NUEVAS LAPTOPS
    int numero_laptops;
    cin>>numero_laptops;

    //$ SELECCION DE MODO DE CREACION (AUTOMATICA O MANUAL)
    int opc;
    cin>>opc;

    if(opc==1){
      //** AUTOMATICO **
      for(int i=0; i<numero_laptops; i++){
        vector<string> laptop={};
        ostringstream os;
        os<<"L"<<setw(4)<<setfill('0')<<(i+1);
        laptop.push_back(os.str());
        for(int j=0; j<6; j++){
          laptop.push_back("0");
        }
        laptop.push_back("");
        laptop.push_back("");
        laptop.push_back("");
        laptop.push_back("habilitado");

        horarios_data.push_back(laptop);
      }

    } else {
      //** MANUAL **
      for(int i=0; i<numero_laptops; i++){
        system("cls");
        string codigo;
        int opc;

        gotoxy(0,0);
        cout<<"LAPTOP NRO"<<(i+1)<<endl;
        cout<<"CODIGO: ";
        cin>>codigo;

        cout<<"AUTO(1) O MANUAL (0): ";
        cin>>opc;

        if(opc==1){
          //* CARACTERISTICAS AUTOMATICAS*
          vector<string> laptop={};
          ostringstream os;
          os<<"L"<<codigo;
          laptop.push_back(os.str());
          for(int j=0; j<6; j++){
            laptop.push_back("0");
          }
          laptop.push_back("");
          laptop.push_back("");
          laptop.push_back("");
          laptop.push_back("habilitado");

          horarios_data.push_back(laptop);

        } else {
          //* CARACTERISTICAS MANUAL*
          string procesador, grafica, ram;

          vector<string> laptop={};
          ostringstream os;
          os<<"L"<<codigo;
          laptop.push_back(os.str());
          for(int j=0; j<6; j++){
            laptop.push_back("0");
          }
          cout<<"PROCESADOR: ";
          cin.ignore();
          getline(cin, procesador);
          cout<<"GRAFICA: ";
          getline(cin, grafica);
          cout<<"RAM: ";
          getline(cin, ram);

          laptop.push_back(""+procesador+"");
          laptop.push_back(""+grafica+"");
          laptop.push_back(""+ram+"");
          laptop.push_back("habilitado");

          horarios_data.push_back(laptop);
        }
      }
    }


    //$ GUARDADO DE HORARIOS_DATA.CSV
    ofstream file2("horarios_data.csv");
    
    for(int i=0; i<horarios_data.size(); i++){
      for(int j=0; j<horarios_data[i].size(); j++){
        file2<<horarios_data[i][j];
        if(j<horarios_data[i].size()-1){
          file2<<",";
        }
      }
      file2<<"\n";
    }

    file2.close();

    getch();
  }
}

void GestionarLaptops::añadir_laptop(){
  //$ HORARIOS_DATA.CSV
  vector<vector<string>> horarios_data;
  ifstream file("horarios_data.csv");
  string linea;

  horarios_data.clear();

  while(getline(file, linea)){
    vector<string> horarios={};
    string horario="";
    stringstream ss(linea);

    while(getline(ss, horario, ',')){
      horarios.push_back(horario);
    }
    horarios_data.push_back(horarios);
  }
  file.close();

  //$ PINTADO DE VENTANA
  change_color(112);
  system("cls");
  gotoxy(0,0);
  show_cursor();

  //$ CANTIDAD DE LAPTOPS A AÑADIR
  int numero_laptops;
  cout<<"CANTIDAD DE LAPTOPS A ANADIR: ";
  cin>>numero_laptops;

  //$ SELECCION DE MODO DE CREACION (AUTOMATICA O MANUAL)
  int opc;
  cout<<"AUTOMATICO(1) O MANUAL(0): ";
  cin>>opc;

  if(opc==1){
    //** AUTOMATICO **
    int i=0, aux=0;
    while(i<numero_laptops){
      bool encontrado=false;
      vector<string> laptop={};
      ostringstream os;
      os<<"L"<<setw(4)<<setfill('0')<<(aux+1);

      for(int j=0; j<horarios_data.size(); j++){
        if(horarios_data[j][0]==os.str()){
          encontrado=true;
          break;
        }
      }

      if(!encontrado){
        laptop.push_back(os.str());
        for(int k=0; k<6; k++){
          laptop.push_back("0");
        }
        laptop.push_back("");
        laptop.push_back("");
        laptop.push_back("");
        laptop.push_back("habilitado");
        horarios_data.push_back(laptop);
        i++;
      }
      aux++;
    }

  } else {
    //** MANUAL **
    for(int i=0; i<numero_laptops; i++){
      system("cls");
      string codigo;
      int opc;
      bool encontrado=false;

      gotoxy(0,0);
      cout<<"LAPTOP NRO"<<(i+1)<<endl;
      cout<<"CODIGO: ";

      do{
        encontrado=false;
        cin>>codigo;
        for(int i=0; i<horarios_data.size(); i++){
          if(horarios_data[i][0]=="L"+codigo){
            encontrado=true;
            break;
          }
        }
      } while(encontrado);

      cout<<"AUTO(1) O MANUAL (0): ";
      cin>>opc;

      if(opc==1){
        //* CARACTERISTICAS AUTOMATICAS*
        vector<string> laptop={};
        ostringstream os;
        os<<"L"<<codigo;
        laptop.push_back(os.str());
        for(int j=0; j<6; j++){
          laptop.push_back("0");
        }
        laptop.push_back("");
        laptop.push_back("");
        laptop.push_back("");
        laptop.push_back("habilitado");

        horarios_data.push_back(laptop);

      } else {
        //* CARACTERISTICAS MANUAL*
        string procesador, grafica, ram;

        vector<string> laptop={};
        ostringstream os;
        os<<"L"<<codigo;
        laptop.push_back(os.str());
        for(int j=0; j<6; j++){
          laptop.push_back("0");
        }
        cout<<"PROCESADOR: ";
        cin.ignore();
        getline(cin, procesador);
        cout<<"GRAFICA: ";
        getline(cin, grafica);
        cout<<"RAM: ";
        getline(cin, ram);

        laptop.push_back(""+procesador+"");
        laptop.push_back(""+grafica+"");
        laptop.push_back(""+ram+"");
        laptop.push_back("habilitado");

        horarios_data.push_back(laptop);
      }
    }
  }


  //$ GUARDADO DE HORARIOS_DATA.CSV
  ofstream file2("horarios_data.csv");
  
  for(int i=0; i<horarios_data.size(); i++){
    for(int j=0; j<horarios_data[i].size(); j++){
      file2<<horarios_data[i][j];
      if(j<horarios_data[i].size()-1){
        file2<<",";
      }
    }
    file2<<"\n";
  }

  file2.close();
}

void GestionarLaptops::editar_laptop(){
  //$ HORARIOS_DATA.CSV
  vector<vector<string>> horarios_data;
  ifstream file("horarios_data.csv");
  string linea;

  horarios_data.clear();

  while(getline(file, linea)){
    vector<string> horarios={};
    string horario="";
    stringstream ss(linea);

    while(getline(ss, horario, ',')){
      horarios.push_back(horario);
    }
    horarios_data.push_back(horarios);
  }
  file.close();

  //$ INGRESO DE LOS CAMBIOS
  string codigo, procesador, grafica, ram;
  cout<<"CODIGO: ";
  cin>>codigo;

  cout<<"MODIFICAR PROCESADOR: ";
  cin.ignore();
  getline(cin, procesador);
  cout<<"MODIFICAR GRAFICA: ";
  getline(cin, grafica);
  cout<<"MODIFICAR RAM: ";
  getline(cin, ram);

  //$ EDITAR DATOS
  for(int i=0; i<horarios_data.size(); i++){
    if(horarios_data[i][0]==codigo){
      horarios_data[i][7]=procesador;
      horarios_data[i][8]=grafica;
      horarios_data[i][9]=ram;
      break;
    }
  }

  //$ GUARDADO DE HORARIOS_DATA.CSV
  ofstream file2("horarios_data.csv");
  
  for(int i=0; i<horarios_data.size(); i++){
    for(int j=0; j<horarios_data[i].size(); j++){
      file2<<horarios_data[i][j];
      if(j<horarios_data[i].size()-1){
        file2<<",";
      }
    }
    file2<<"\n";
  }

  file2.close();
}

void GestionarLaptops::eliminar_laptop(){
  //$ HORARIOS_DATA.CSV
  vector<vector<string>> horarios_data;
  ifstream file("horarios_data.csv");
  string linea;

  horarios_data.clear();

  while(getline(file, linea)){
    vector<string> horarios={};
    string horario="";
    stringstream ss(linea);

    while(getline(ss, horario, ',')){
      horarios.push_back(horario);
    }
    horarios_data.push_back(horarios);
  }
  file.close();

  //$ INGRESO DEL CODIGO
  string codigo, procesador, grafica, ram;
  cout<<"CODIGO: ";
  cin>>codigo;

  //$ ELIMINAR LAPTOP
  for(int i=0; i<horarios_data.size(); i++){
    if(horarios_data[i][0]==codigo){
      horarios_data.erase(horarios_data.begin()+i);
    }
  }

  //$ GUARDADO DE HORARIOS_DATA.CSV
  ofstream file2("horarios_data.csv");
  
  for(int i=0; i<horarios_data.size(); i++){
    for(int j=0; j<horarios_data[i].size(); j++){
      file2<<horarios_data[i][j];
      if(j<horarios_data[i].size()-1){
        file2<<",";
      }
    }
    file2<<"\n";
  }
  file2.close();
}

void GestionarLaptops::estado_laptop(){
  //$ HORARIOS_DATA.CSV
  vector<vector<string>> horarios_data;
  ifstream file("horarios_data.csv");
  string linea;

  horarios_data.clear();

  while(getline(file, linea)){
    vector<string> horarios={};
    string horario="";
    stringstream ss(linea);

    while(getline(ss, horario, ',')){
      horarios.push_back(horario);
    }
    horarios_data.push_back(horarios);
  }
  file.close();

  //$ INGRESO DE LOS CAMBIOS
  string codigo, estado;
  cout<<"CODIGO: ";
  cin>>codigo;

  cout<<"MODIFICAR ESTADO: ";
  cin.ignore();
  getline(cin, estado);

  //$ EDITAR ESTADO
  for(int i=0; i<horarios_data.size(); i++){
    if(horarios_data[i][0]==codigo){
      //* ESTADO PUEDE SER -> Habilitado, Mantenimiento, Malogrado, No Disponible
      horarios_data[i][10]=estado;
      break;
    }
  }

  //$ GUARDADO DE HORARIOS_DATA.CSV
  ofstream file2("horarios_data.csv");
  
  for(int i=0; i<horarios_data.size(); i++){
    for(int j=0; j<horarios_data[i].size(); j++){
      file2<<horarios_data[i][j];
      if(j<horarios_data[i].size()-1){
        file2<<",";
      }
    }
    file2<<"\n";
  }

  file2.close();
}

void GestionarLaptops::seleccionar_opcion(GestorVentanas& gestor){
  int tecla=72, opc=1;
  int x=1, y=1;

  while(tecla!=13){
    if(tecla==72 && y>1){y--;}
    if(tecla==80 && y<3){y++;}
    if(tecla==75 && x>1){x--;}
    if(tecla==77 && x<3){x++;}

    if(x==1 && y==1){
      change_color(241);
      button(25, 1, 22, 9, "Ver Reservas");
      change_color(240);
      button(25, 1, 48, 9, "Cantidad de Laptops");
      button(25, 1, 74, 9, "Anadir Laptop");
      button(25, 1, 22, 13, "Editar Laptop");
      button(25, 1, 48, 13, "Eliminar Laptop");
      button(25, 1, 74, 13, "Estado de Laptops");
      button(25, 1, 48, 17, "SALIR");
      opc=1;

    } else if(x==2 && y==1){
      button(25, 1, 22, 9, "Ver Reservas");
      change_color(241);
      button(25, 1, 48, 9, "Cantidad de Laptops");
      change_color(240);
      button(25, 1, 74, 9, "Anadir Laptop");
      button(25, 1, 22, 13, "Editar Laptop");
      button(25, 1, 48, 13, "Eliminar Laptop");
      button(25, 1, 74, 13, "Estado de Laptops");
      button(25, 1, 48, 17, "SALIR");
      opc=2;

    } else if(x==3 && y==1){
      button(25, 1, 22, 9, "Ver Reservas");
      button(25, 1, 48, 9, "Cantidad de Laptops");
      change_color(241);
      button(25, 1, 74, 9, "Anadir Laptop");
      change_color(240);
      button(25, 1, 22, 13, "Editar Laptop");
      button(25, 1, 48, 13, "Eliminar Laptop");
      button(25, 1, 74, 13, "Estado de Laptops");
      button(25, 1, 48, 17, "SALIR");
      opc=3;

    } else if(x==1 && y==2){
      button(25, 1, 22, 9, "Ver Reservas");
      button(25, 1, 48, 9, "Cantidad de Laptops");
      button(25, 1, 74, 9, "Anadir Laptop");
      change_color(241);
      button(25, 1, 22, 13, "Editar Laptop");
      change_color(240);
      button(25, 1, 48, 13, "Eliminar Laptop");
      button(25, 1, 74, 13, "Estado de Laptops");
      button(25, 1, 48, 17, "SALIR");
      opc=4;

    } else if(x==2 && y==2){
      button(25, 1, 22, 9, "Ver Reservas");
      button(25, 1, 48, 9, "Cantidad de Laptops");
      button(25, 1, 74, 9, "Anadir Laptop");
      button(25, 1, 22, 13, "Editar Laptop");
      change_color(241);
      button(25, 1, 48, 13, "Eliminar Laptop");
      change_color(240);
      button(25, 1, 74, 13, "Estado de Laptops");
      button(25, 1, 48, 17, "SALIR");
      opc=5;

    } else if(x==3 && y==2){
      button(25, 1, 22, 9, "Ver Reservas");
      button(25, 1, 48, 9, "Cantidad de Laptops");
      button(25, 1, 74, 9, "Anadir Laptop");
      button(25, 1, 22, 13, "Editar Laptop");
      button(25, 1, 48, 13, "Eliminar Laptop");
      change_color(241);
      button(25, 1, 74, 13, "Estado de Laptops");
      change_color(240);
      button(25, 1, 48, 17, "SALIR");
      opc=6;

    } else if(y=3){
      button(25, 1, 22, 9, "Ver Reservas");
      button(25, 1, 48, 9, "Cantidad de Laptops");
      button(25, 1, 74, 9, "Anadir Laptop");
      button(25, 1, 22, 13, "Editar Laptop");
      button(25, 1, 48, 13, "Eliminar Laptop");
      button(25, 1, 74, 13, "Estado de Laptops");
      change_color(241);
      button(25, 1, 48, 17, "SALIR");
      change_color(240);
      opc=7;
    }

    tecla=_getch();
  }

  switch(opc){
    case 1:
      break;
    case 2:
      GestionarLaptops::cantidad_laptops();
      break;
    case 3:
      GestionarLaptops::añadir_laptop();
      break;
    case 4:
      GestionarLaptops::editar_laptop();
      break;
    case 5:
      GestionarLaptops::eliminar_laptop();
      break;
    case 6:
      GestionarLaptops::estado_laptop();
      break;
    case 7:
      gestor.cambiar_ventana(Ventanas::ADMINMAIN);
      break;
  }
}

void GestionarLaptops::main(GestorVentanas& gestor) {
  mostrar();
  seleccionar_opcion(gestor);
}