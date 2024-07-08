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
#include <limits>
#include <cmath>

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

void GestionarLaptops::ver_laptops(){
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
    if(horarios[0][0]=='L'){
      horarios_data.push_back(horarios);
    }
  }
  file.close();
  
  //$ PINTAR PANTALLA
  change_color(112);
  system("cls");
  change_color(240);
  rectangle(100, 26, 10, 1);

  change_color(244);
  gotoxy(52, 3);
  cout<<"Laptops en el sistema";
  change_color(240);

  //$ PINTAR LISTADO DE LAPTOPS
  change_color(241);
  button(9, 1, 13, 5, "CODIGO");
  button(7, 1, 20, 5, "08-10");
  button(7, 1, 26, 5, "10-12");
  button(7, 1, 32, 5, "12-14");
  button(7, 1, 38, 5, "14-16");
  button(7, 1, 44, 5, "16-18");
  button(7, 1, 50, 5, "18-20");
  button(13, 1, 56, 5, "PROCESADOR");
  button(13, 1, 68, 5, "GRAFICA");
  button(13, 1, 80, 5, "RAM");
  button(15, 1, 92, 5, "ESTADO");
  change_color(240);

  int numero_laptops = horarios_data.size();
  int numero_ventanas = ceil(numero_laptops/20.0);

  int tecla=75;
  int ventana_actual=1;
  while(tecla!=13){
    //$ LIMPIAR LA PANTALLA
    change_color(240);
    for(int i=8; i<28; i++){
      for(int j=13; j<107; j++){
        gotoxy(j, i);
        cout<<" ";
      }
    }
    change_color(240);

    ostringstream numero_ventana;
    numero_ventana<<setw(2)<<setfill('0')<<(ventana_actual);
    ostringstream total_ventanas;
    total_ventanas<<setw(2)<<setfill('0')<<numero_ventanas;
    change_color(241);
    gotoxy(86, 28);
    cout<<"<--Pagina "<<numero_ventana.str()<<" / "<<total_ventanas.str()<<"-->";
    change_color(240);

    int final;
    if(20*(ventana_actual-1)+19<numero_laptops){
      final=20*(ventana_actual);
    } else {
      final=20*(ventana_actual-1)+(numero_laptops%20);
    }

    int aux_y=8;
    for(int i=20*(ventana_actual-1); i<final; i++){
      int color;
      if(i%2==0){
        color=112;
      } else {
        color=240;
      }

      change_color(color);
      //*CODIGO
      gotoxy(13, aux_y);
      cout<<"|      ";
      gotoxy(14+((6-horarios_data[i][0].size())/2), aux_y);
      cout<<horarios_data[i][0];

      //*HORARIOS
      gotoxy(20, aux_y);
      cout<<"|";
      if(horarios_data[i][1]=="0"){
        change_color(color+2);
        cout<<"LIBRE";
      } else {
        change_color(color+4);
        cout<<"  NO ";
      }
      change_color(color);
      cout<<"|";

      if(horarios_data[i][2]=="0"){
        change_color(color+2);
        cout<<"LIBRE";
      } else {
        change_color(color+4);
        cout<<"  NO ";
      }
      change_color(color);
      cout<<"|";

      if(horarios_data[i][3]=="0"){
        change_color(color+2);
        cout<<"LIBRE";
      } else {
        change_color(color+4);
        cout<<"  NO ";
      }
      change_color(color);
      cout<<"|";

      if(horarios_data[i][4]=="0"){
        change_color(color+2);
        cout<<"LIBRE";
      } else {
        change_color(color+4);
        cout<<"  NO ";
      }
      change_color(color);
      cout<<"|";

      if(horarios_data[i][5]=="0"){
        change_color(color+2);
        cout<<"LIBRE";
      } else {
        change_color(color+4);
        cout<<"  NO ";
      }
      change_color(color);
      cout<<"|";

      if(horarios_data[i][6]=="0"){
        change_color(color+2);
        cout<<"LIBRE";
      } else {
        change_color(color+4);
        cout<<"  NO ";
      }
      change_color(color);

      //*PROCESADOR
      cout<<"|           ";
      gotoxy(57+((11-horarios_data[i][7].size())/2), aux_y);
      cout<<horarios_data[i][7];

      //*GRAFICA
      gotoxy(68, aux_y);
      cout<<"|           ";
      gotoxy(69+((11-horarios_data[i][8].size())/2), aux_y);
      cout<<horarios_data[i][8];

      //*RAM
      gotoxy(80, aux_y);
      cout<<"|           ";
      gotoxy(81+((11-horarios_data[i][9].size())/2), aux_y);
      cout<<horarios_data[i][9];

      //*ESTADO
      gotoxy(92, aux_y);
      cout<<"|             |";
      gotoxy(93+((13-horarios_data[i][10].size())/2), aux_y);
      cout<<horarios_data[i][10];

      aux_y++;
    }
    
    tecla=_getch();

    if(tecla==75 && ventana_actual>1){
      ventana_actual--;
    } else if (tecla==77 && ventana_actual<numero_ventanas){
      ventana_actual++;
    }
  }

  getch();
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
    do{
      gotoxy(65, 9);
      cout<<"    |    ";
      gotoxy(65, 9);
      cin>>numero_laptops;

      if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }

    } while(to_string(numero_laptops).length()>4 || numero_laptops==0);

    //$ SELECCION DE MODO DE CREACION (AUTOMATICA O MANUAL)
    int tecla=75, opc=1;
    hide_cursor();
    while(tecla!=13){
      if(tecla==75){
        change_color(241);
        button(14, 1, 47, 14, "Automatico");
        change_color(240);
        button(14, 1, 64, 14, "Manual");
        opc=1;
      } else if (tecla==77){
        button(14, 1, 47, 14, "Automatico");
        change_color(241);
        button(14, 1, 64, 14, "Manual");
        change_color(240);
        opc=2;
      }
      tecla=_getch();
    }
    show_cursor();

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
        laptop.push_back("Habilitado");

        horarios_data.push_back(laptop);
      }

    } else {
      //** MANUAL **
      for(int i=0; i<numero_laptops; i++){
        //! PINTADO DE MANUAL
        string codigo;
        bool encontrado=false;

        do{
          encontrado=false;

          change_color(112);
          system("cls");
          change_color(240);
          rectangle(83, 20, 19, 4);

          change_color(244);
          gotoxy(56,6);
          cout<<"LAPTOP NRO"<<(i+1);
          change_color(240);

          gotoxy(50, 9);
          cout<<"CODIGO: ";
          rectangle(7, 1, 58, 8);
          gotoxy(59,9);
          cout<<"L";

          gotoxy(36, 12);
          cout<<"Como desea crear las especificaciones de esta laptop?";

          button(16,1,40,14, "Automatico");
          button(16,1,65,14, "Manual");

          if(codigo.size()>4){
            change_color(244);
            gotoxy(70,8);
            cout<<"CODIGO MUY LARGO";
            change_color(240);
          }

          change_color(241);
          gotoxy(30, 23);
          cout<<"'AUTOMATICO' hara que las laptops no tengan especificaciones";
          gotoxy(29, 24);
          cout<<"'MANUAL' hara que escribas las especificaciones de las laptops";
          change_color(240);

          gotoxy(60,9);
          cin>>codigo;
          
          for(int i=0; i<horarios_data.size(); i++){
            if(horarios_data[i][0]== "L"+codigo){
              encontrado=true;
              break;
            }
          }
        } while (codigo.size()>4 || encontrado==true);
        
        //!ELECCION DE ESPECIFICAIONES (AUTO O MANUAL)
        int tecla=75, opc=1;
        hide_cursor();
        while(tecla!=13){
          if(tecla==75){
            change_color(241);
            button(16,1,40,14, "Automatico");
            change_color(240);
            button(16,1,65,14, "Manual");
            opc=1;
          } else if (tecla==77){
            button(16,1,40,14, "Automatico");
            change_color(241);
            button(16,1,65,14, "Manual");
            change_color(240);
            opc=2;
          }
          tecla=_getch();
        }
        show_cursor();

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
          laptop.push_back("Habilitado");

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
          
          cin.ignore();
          do{
            gotoxy(35,20);
            cout<<"                    ";
            gotoxy(35,18);
            cout<<"PROCESADOR";
            rectangle(13, 1, 34, 19);
            gotoxy(35,20);
            getline(cin, procesador);
          } while(procesador.size()>11);
          
          do{
            gotoxy(55,20);
            cout<<"                    ";
            gotoxy(57, 18);
            cout<<"GRAFICA";
            rectangle(13, 1, 54, 19);
            gotoxy(55,20);
            getline(cin, grafica);
          } while(grafica.size()>11);
          
          do{
            gotoxy(75,20);
            cout<<"                   ";
            gotoxy(79, 18);
            cout<<"RAM";
            rectangle(13, 1, 74, 19);
            gotoxy(75,20);
            getline(cin, ram);
          } while(ram.size()>11);
          
          laptop.push_back(""+procesador+"");
          laptop.push_back(""+grafica+"");
          laptop.push_back(""+ram+"");
          laptop.push_back("Habilitado");

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
}

void GestionarLaptops::anadir_laptop(){
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

  change_color(240);
  rectangle(83, 18, 19, 4);

  change_color(244);
  gotoxy(55, 6);
  cout<<"AÑADIR LAPTOPS";
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

  //$ CANTIDAD DE LAPTOPS A AÑADIR
  int numero_laptops;
  show_cursor();
  do{
    gotoxy(65, 9);
    cout<<"    |    ";
    gotoxy(65, 9);
    cin>>numero_laptops;

    if(cin.fail()){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

  } while(to_string(numero_laptops).length()>4 || numero_laptops==0);
  hide_cursor();

  //$ SELECCION DE MODO DE CREACION (AUTOMATICA O MANUAL)
  int tecla=75, opc=1;
  hide_cursor();
  while(tecla!=13){
    if(tecla==75){
      change_color(241);
      button(14, 1, 47, 14, "Automatico");
      change_color(240);
      button(14, 1, 64, 14, "Manual");
      opc=1;
    } else if (tecla==77){
      button(14, 1, 47, 14, "Automatico");
      change_color(241);
      button(14, 1, 64, 14, "Manual");
      change_color(240);
      opc=2;
    }
    tecla=_getch();
  }
  show_cursor();

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
        laptop.push_back("Habilitado");
        horarios_data.push_back(laptop);
        i++;
      }
      aux++;
    }

  } else {
    //** MANUAL **
    for(int i=0; i<numero_laptops; i++){
      //! PINTADO DE MANUAL
      string codigo;
      bool encontrado=false;

      do{
        encontrado=false;

        change_color(112);
        system("cls");
        change_color(240);
        rectangle(83, 20, 19, 4);

        change_color(244);
        gotoxy(56,6);
        cout<<"LAPTOP NRO"<<(i+1);
        change_color(240);

        gotoxy(50, 9);
        cout<<"CODIGO: ";
        rectangle(7, 1, 58, 8);
        gotoxy(59,9);
        cout<<"L";

        gotoxy(36, 12);
        cout<<"Como desea crear las especificaciones de esta laptop?";

        button(16,1,40,14, "Automatico");
        button(16,1,65,14, "Manual");

        if(codigo.size()>4){
          change_color(244);
          gotoxy(70,8);
          cout<<"CODIGO MUY LARGO";
          change_color(240);
        }

        change_color(241);
        gotoxy(30, 23);
        cout<<"'AUTOMATICO' hara que las laptops no tengan especificaciones";
        gotoxy(29, 24);
        cout<<"'MANUAL' hara que escribas las especificaciones de las laptops";
        change_color(240);

        gotoxy(60,9);
        cin>>codigo;
        
        for(int i=0; i<horarios_data.size(); i++){
          if(horarios_data[i][0]== "L"+codigo){
            encontrado=true;
            break;
          }
        }
      } while (codigo.size()>4 || encontrado==true);

      //!ELECCION DE ESPECIFICACIONES (AUTOMATICAS O MANUAL)
      int tecla=75, opc=1;
      hide_cursor();
      while(tecla!=13){
        if(tecla==75){
          change_color(241);
          button(16,1,40,14, "Automatico");
          change_color(240);
          button(16,1,65,14, "Manual");
          opc=1;
        } else if (tecla==77){
          button(16,1,40,14, "Automatico");
          change_color(241);
          button(16,1,65,14, "Manual");
          change_color(240);
          opc=2;
        }
        tecla=_getch();
      }
      show_cursor();

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
        laptop.push_back("Habilitado");

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

        cin.ignore();
        do{
          gotoxy(35,20);
          cout<<"                    ";
          gotoxy(35,18);
          cout<<"PROCESADOR";
          rectangle(13, 1, 34, 19);
          gotoxy(35,20);
          getline(cin, procesador);
        } while(procesador.size()>11);
        
        do{
          gotoxy(55,20);
          cout<<"                    ";
          gotoxy(57, 18);
          cout<<"GRAFICA";
          rectangle(13, 1, 54, 19);
          gotoxy(55,20);
          getline(cin, grafica);
        } while(grafica.size()>11);
        
        do{
          gotoxy(75,20);
          cout<<"                   ";
          gotoxy(79, 18);
          cout<<"RAM";
          rectangle(13, 1, 74, 19);
          gotoxy(75,20);
          getline(cin, ram);
        } while(ram.size()>11);

        laptop.push_back(""+procesador+"");
        laptop.push_back(""+grafica+"");
        laptop.push_back(""+ram+"");
        laptop.push_back("Habilitado");

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

  

  //$ INGRESO DEL CODIGO
  string codigo, procesador, grafica, ram;
  bool encontrado;

  show_cursor();
  int fails=-1;
  do{
    fails++;
    if(fails>3){
      change_color(241);
      gotoxy(70, 8);
      cout<<"Presiona enter";
      gotoxy(70, 9);
      cout<<"para ir atras...";
      change_color(240);
      hide_cursor();
      getch();
      return;
    }
    encontrado=false;

    change_color(112);
    system("cls");
    change_color(240);
    rectangle(83, 20, 19, 4);

    change_color(244);
    gotoxy(56,6);
    cout<<"EDITAR LAPTOP";
    change_color(240);

    gotoxy(50, 9);
    cout<<"CODIGO: ";
    rectangle(7, 1, 58, 8);
    gotoxy(59,9);
    cout<<"L";

    if(codigo.size()>4){
      change_color(244);
      gotoxy(70,8);
      cout<<"CODIGO MUY LARGO";
      change_color(240);
    }

    gotoxy(60,9);
    cin>>codigo;
    
    for(int i=0; i<horarios_data.size(); i++){
      if(horarios_data[i][0]== "L"+codigo){
        encontrado=true;
        break;
      }
    }
  } while (codigo.size()>4 || !encontrado);
  hide_cursor();


  //$ INGRESO Y COMPARACION DE LOS CAMBIOS
  button(13, 1, 50, 12, "PROCESADOR");
  button(13, 1, 62, 12, "GRAFICA");
  button(13, 1, 74, 12, "RAM");
  button(16, 1, 35, 14, "ACTUAL");
  button(16, 1, 35, 16, "NUEVOS");

  for(int i=0; i<horarios_data.size(); i++){
    if(horarios_data[i][0]=="L"+codigo){
      procesador=horarios_data[i][7];
      grafica=horarios_data[i][8];
      ram=horarios_data[i][9];
      break;
    }
  }

  gotoxy(40, 24);
  change_color(241);
  cout<<"SI QUIERES DEJARLO VACIO SOLO PRESIONA ENTER";
  change_color(240);

  button(13, 1, 50, 14, procesador);
  button(13, 1, 62, 14, grafica);
  button(13, 1, 74, 14, ram);
  rectangle(13, 1, 50, 16);
  rectangle(13, 1, 62, 16);
  rectangle(13, 1, 74, 16);

  show_cursor();
  cin.ignore();
  do{
    gotoxy(50, 17);
    cout<<"|           |           |           |";
    gotoxy(51,17);
    getline(cin, procesador);
  } while(procesador.size()>11);
  
  do{
    gotoxy(62, 17);
    cout<<"|           |           |        ";
    gotoxy(63,17);
    getline(cin, grafica);
  } while(grafica.size()>11);
  
  do{
    gotoxy(74, 17);
    cout<<"|           |        ";
    gotoxy(75,17);
    getline(cin, ram);
  } while(ram.size()>11);
  hide_cursor();

  //$ EDITAR DATOS O SALIR
  int tecla=75, opc=1;
  while(tecla!=13){
    if(tecla==75){
      change_color(241);
      button(14, 1, 40, 20, "EDITAR");
      change_color(240);
      button(14, 1, 72, 20, "CANCELAR");
      opc=1;
    } else if(tecla==77){
      button(14, 1, 40, 20, "EDITAR");
      change_color(241);
      button(14, 1, 72, 20, "CANCELAR");
      change_color(240);
      opc=2;
    }
    tecla=_getch();
  }

  if(opc==1){
    for(int i=0; i<horarios_data.size(); i++){
      if(horarios_data[i][0]=="L"+codigo){
        horarios_data[i][7]=procesador;
        horarios_data[i][8]=grafica;
        horarios_data[i][9]=ram;
        break;
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

  //$ PINTAR PANTALLA
  change_color(112);
  system("cls");
  change_color(240);
  rectangle(83, 11, 19, 5);

  change_color(244);
  gotoxy(55, 7);
  cout<<"ELIMINAR LAPTOP";
  change_color(240);

  gotoxy(55, 10);
  cout<<"CODIGO: ";
  rectangle(7, 1, 62, 9);
  gotoxy(63,10);
  cout<<"L";

  button(12, 1, 45, 13, "ELIMINAR");
  button(12, 1, 66, 13, "CANCELAR");

  //$ INGRESO DEL CODIGO
  string codigo;

  int fails=-1;
  bool encontrado;
  show_cursor();
  do{
    encontrado=false;
    fails++;
    if(fails>3){
      change_color(241);
      gotoxy(75, 9);
      cout<<"Presiona enter";
      gotoxy(75, 10);
      cout<<"para volver...";
      change_color(240);
      getch();
      hide_cursor();
      return;
    }
    gotoxy(64, 10);
    cout<<"    |     ";
    gotoxy(64, 10);
    cin>>codigo;

    for(int i=0; i<horarios_data.size(); i++){
      if(horarios_data[i][0]=="L"+codigo){
        encontrado=true;
        break;
      }
    }

  } while(codigo.size()>4 || !encontrado);
  hide_cursor();

  //$ ELIMINAR LAPTOP O CANCELAR
  int tecla=75, opc=1;
  while(tecla!=13){
    if(tecla==75){
      change_color(241);
      button(12, 1, 45, 13, "ELIMINAR");
      change_color(240);
      button(12, 1, 66, 13, "CANCELAR");
      opc=1;
    } else if( tecla==77){
      button(12, 1, 45, 13, "ELIMINAR");
      change_color(241);
      button(12, 1, 66, 13, "CANCELAR");
      change_color(240);
      opc=2;
    }
    tecla=_getch();
  }

  if(opc==1){
    for(int i=0; i<horarios_data.size(); i++){
      if(horarios_data[i][0]=="L"+codigo){
        horarios_data.erase(horarios_data.begin()+i);
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

  //$ PINTAR PANTALLA
  change_color(112);
  system("cls");
  change_color(240);
  rectangle(83, 15, 19, 5);

  change_color(244);
  gotoxy(51, 7);
  cout<<"EDITAR ESTADO DE LAPTOP";
  change_color(240);

  gotoxy(55, 10);
  cout<<"CODIGO: ";
  rectangle(7, 1, 62, 9);
  gotoxy(63,10);
  cout<<"L";

  button(15, 1, 26, 13, "Habilitado");
  button(15, 1, 44, 13, "Mantenimiento");
  button(15, 1, 62, 13, "Malogrado");
  button(15, 1, 80, 13, "No Disponible");


  //$ INGRESO DEL CODIGO
  string codigo;

  int fails=-1;
  bool encontrado;
  show_cursor();
  do{
    encontrado=false;
    fails++;
    if(fails>3){
      change_color(241);
      gotoxy(75, 9);
      cout<<"Presiona enter";
      gotoxy(75, 10);
      cout<<"para volver...";
      change_color(240);
      getch();
      hide_cursor();
      return;
    }
    gotoxy(64, 10);
    cout<<"    |     ";
    gotoxy(64, 10);
    cin>>codigo;

    for(int i=0; i<horarios_data.size(); i++){
      if(horarios_data[i][0]=="L"+codigo){
        encontrado=true;
        break;
      }
    }

  } while(codigo.size()>4 || !encontrado);
  hide_cursor();

  //$ ESCOGER ESTADO
  string estado;

  int tecla=75, opc=1;
  while(tecla!=13){
    if(tecla==75 && opc>1){
      opc--;
    } else if(tecla==77 && opc<4){
      opc++;
    }

    switch(opc){
      case 1:
        change_color(241);
        button(15, 1, 26, 13, "Habilitado");
        change_color(240);
        button(15, 1, 44, 13, "Mantenimiento");
        button(15, 1, 62, 13, "Malogrado");
        button(15, 1, 80, 13, "No Disponible");
        estado="Habilitado";
        break;
      case 2:
        button(15, 1, 26, 13, "Habilitado");
        change_color(241);
        button(15, 1, 44, 13, "Mantenimiento");
        change_color(240);
        button(15, 1, 62, 13, "Malogrado");
        button(15, 1, 80, 13, "No Disponible");
        estado="Mantenimiento";
        break;
      case 3:
        button(15, 1, 26, 13, "Habilitado");
        button(15, 1, 44, 13, "Mantenimiento");
        change_color(241);
        button(15, 1, 62, 13, "Malogrado");
        change_color(240);
        button(15, 1, 80, 13, "No Disponible");
        estado="Malogrado";
        break;
      case 4:
        button(15, 1, 26, 13, "Habilitado");
        button(15, 1, 44, 13, "Mantenimiento");
        button(15, 1, 62, 13, "Malogrado");
        change_color(241);
        button(15, 1, 80, 13, "No Disponible");
        change_color(240);
        estado="No Disponible";
        break;
    }

    tecla=_getch();
  }

  //$ EDITAR ESTADO O CANCELAR

  int tecla2=75, opc2=1;
  while(tecla2!=13){
    if(tecla2==75){
      change_color(241);
      button(12, 1, 46, 17, "EDITAR");
      change_color(240);
      button(12, 1, 63, 17, "CANCELAR");
      opc2=1;
    } else if(tecla2==77){
      button(12, 1, 46, 17, "EDITAR");
      change_color(241);
      button(12, 1, 63, 17, "CANCELAR");
      change_color(240);
      opc2=2;
    }
    tecla2=_getch();
  }

  if(opc2==1){
    for(int i=0; i<horarios_data.size(); i++){
      if(horarios_data[i][0]=="L"+codigo){
        horarios_data[i][10]=estado;
        break;
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
      button(25, 1, 22, 9, "Ver Laptops");
      change_color(240);
      button(25, 1, 48, 9, "Cantidad de Laptops");
      button(25, 1, 74, 9, "Anadir Laptop");
      button(25, 1, 22, 13, "Editar Laptop");
      button(25, 1, 48, 13, "Eliminar Laptop");
      button(25, 1, 74, 13, "Estado de Laptops");
      button(25, 1, 48, 17, "SALIR");
      opc=1;

    } else if(x==2 && y==1){
      button(25, 1, 22, 9, "Ver Laptops");
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
      button(25, 1, 22, 9, "Ver Laptops");
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
      button(25, 1, 22, 9, "Ver Laptops");
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
      button(25, 1, 22, 9, "Ver Laptops");
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
      button(25, 1, 22, 9, "Ver Laptops");
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
      button(25, 1, 22, 9, "Ver Laptops");
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
      GestionarLaptops::ver_laptops();
      break;
    case 2:
      GestionarLaptops::cantidad_laptops();
      break;
    case 3:
      GestionarLaptops::anadir_laptop();
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