#include "GestorVentanas.h"
#include "UserLogin.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "functions.h"
#include "VerificarUsuario.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string UserLogin::sanciones;
vector<vector<int>> UserLogin::historial_sanciones;

void UserLogin::mostrar(){
  show_cursor();

  change_color(112);
  system("cls");

  change_color(113);
  gotoxy(45,2);
  cout<<"SI ES LA PRIMERA VEZ QUE INGRESA";
  gotoxy(36,3);
  cout<<"SE CREARA UNA CUENTA CON LA CONTRASEÑA QUE COLOQUE";
  
  change_color(240);
  rectangle(46, 20, 38, 5);

  gotoxy(39, 7);
  cout<<"--------------------------------------------";
  change_color(244);
  gotoxy(53,6);
  cout<<"INICIO DE SESION";
  change_color(240);

  gotoxy(45,9);
  cout<<"ALUMNO, INGRESE SUS CREDENCIALES";

  gotoxy(45,12);
  cout<<"CODIGO:";
  gotoxy(45,13);
  cout<<"+------------------------------+";
  gotoxy(45,14);
  cout<<"|                              |";
  gotoxy(45,15);
  cout<<"+------------------------------+";

  gotoxy(45,17);
  cout<<"CONTRASENA:";
  gotoxy(45,18);
  cout<<"+------------------------------+";
  gotoxy(45,19);
  cout<<"|                              |";
  gotoxy(45,20);
  cout<<"+------------------------------+";

  gotoxy(43, 22);
  cout<<"+------------+";
  gotoxy(43, 23);
  cout<<"|  INGRESAR  |";
  gotoxy(43, 24);
  cout<<"+------------+";

  gotoxy(66, 22);
  cout<<"+-----------+";
  gotoxy(66, 23);
  cout<<"|   SALIR   |";
  gotoxy(66, 24);
  cout<<"+-----------+";

}

void UserLogin::ingresar_credenciales(GestorVentanas& gestor){
  gotoxy(46,14);
  cin>>gestor.codigo;
  gotoxy(46,19);
  cin>>gestor.contrasena;
}

void UserLogin::validar_credenciales(GestorVentanas& gestor){
  system("cls");
  int verificacion = VerificarUsuario(gestor.codigo, gestor.contrasena, gestor);
  switch (verificacion){
    case 1:
      //$ INGRESO NORMAL
      gestor.cambiar_ventana(Ventanas::USERMAIN);
      break;
    case 2:
      //$ NUEVO MATRICULA
      gotoxy(46, 10);
      cout<<"+-------------------------------+";
      gotoxy(46, 11);
      cout<<"|         CUENTA CREADA         |";
      gotoxy(46, 12);
      cout<<"+-------------------------------+";
      gestor.cambiar_ventana(Ventanas::USERMAIN);
      getch();
      break;
    case 3:
      //$ CREDENCIALES INCORRECTAS
      gotoxy(45, 10);
      cout<<"+------------------------------+";
      gotoxy(45, 11);
      cout<<"|   CREDENCIALES INCORRECTAS   |";
      gotoxy(45, 12);
      cout<<"+------------------------------+";
      change_color(244);
      gotoxy(31, 14);
      cout<<"Ya existe una cuenta con este codigo y la contraseña no coincide";
      change_color(240);
      gotoxy(39, 15);
      cout<<"En caso que usted no haya creado esta cuenta,";
      gotoxy(45, 16);
      cout<<"o se haya olvidado su contraseña";
      gotoxy(37, 17);
      cout<<"acerquese a recepcion para solucionar el problema";
      getch();
      break;
    case 4:
      //$ NO ES ALUMNO
      gotoxy(45, 10);
      cout<<"+------------------------------+";
      gotoxy(45, 11);
      cout<<"|         NO ES ALUMNO         |";
      gotoxy(45, 12);
      cout<<"+------------------------------+";
      change_color(244);
      gotoxy(37, 14);
      cout<<"Este codigo no se encuentra en la base de datos,";
      gotoxy(47, 15);
      cout<<"por favor verifique el mismo";
      gotoxy(40, 16);
      cout<<"Si el error persiste, acerquese a recepcion";
      change_color(240);
      getch();
      break;
  }
}

void UserLogin::seleccionar_opcion(GestorVentanas& gestor){
  int opc=1, tecla=75;
  hide_cursor();
  while(tecla!=13){
    switch(tecla){
			case 75:
        change_color(241);
				gotoxy(43, 22);
        cout<<"+------------+";
        gotoxy(41, 23);
        cout<<"->|  INGRESAR  |";
        gotoxy(43, 24);
        cout<<"+------------+";
        change_color(240);

        gotoxy(66, 22);
        cout<<"+-----------+";
        gotoxy(64, 23);
        cout<<"  |   SALIR   |";
        gotoxy(66, 24);
        cout<<"+-----------+";

				opc=1;
				break;
			case 77:
				gotoxy(43, 22);
        cout<<"+------------+";
        gotoxy(41, 23);
        cout<<"  |  INGRESAR  |";
        gotoxy(43, 24);
        cout<<"+------------+";

        change_color(241);
        gotoxy(66, 22);
        cout<<"+-----------+";
        gotoxy(64, 23);
        cout<<"->|   SALIR   |";
        gotoxy(66, 24);
        cout<<"+-----------+";
        change_color(240);
				
				opc=0;
				break;
		}
		
		tecla = _getch();
  }

  switch(opc){
    case 1: {
      ifstream file_sanciones("sanciones.csv");
      string linea_h;

      UserLogin::historial_sanciones.clear();

      while(getline(file_sanciones, linea_h)){
        vector<int> history_sanciones;
        string valor1;
        stringstream ss3(linea_h);

        while(getline(ss3, valor1, ',')){
          history_sanciones.push_back(stoi(valor1));
        }
        UserLogin::historial_sanciones.push_back(history_sanciones);
      }
      file_sanciones.close();

      for (int i = 0; i < UserLogin::historial_sanciones.size(); ++i) {
        if(UserLogin::historial_sanciones[i][0] == stoi(gestor.codigo)){
          UserLogin::sanciones = std::to_string(UserLogin::historial_sanciones[i][1]);
          break;
        }
      }
      if(stoi(UserLogin::sanciones)==3){
        system("cls");
        change_color(244);
        gotoxy(45, 10);
        cout<<"ESTAS BETADO DEL SISTEMA";
        change_color(240);
        getch();
      }else{
        UserLogin::validar_credenciales(gestor);
      }
      break;
    }
    case 0:
      gestor.cambiar_ventana(Ventanas::MAINWINDOW);
      break;
  }
}

void UserLogin::main(GestorVentanas& gestor){
  UserLogin::mostrar();
  UserLogin::ingresar_credenciales(gestor);
  UserLogin::seleccionar_opcion(gestor);
}