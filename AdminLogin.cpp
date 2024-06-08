#include "GestorVentanas.h"
#include "UserLogin.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "functions.h"

using namespace std;

void AdminLogin::mostrar(){
  show_cursor();

  change_color(112);
  system("cls");
  
  change_color(240);
  rectangle(46, 20, 38, 5);

  gotoxy(39, 7);
  cout<<"--------------------------------------------";
  change_color(244);
  gotoxy(53,6);
  cout<<"INICIO DE SESION";
  change_color(240);

  gotoxy(45,9);
  cout<<"TRABJADOR, INGRESE SUS CREDENCIALES";

  gotoxy(45,12);
  cout<<"USUARIO:";
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

void AdminLogin::ingresar_credenciales(GestorVentanas& gestor){
  gotoxy(46,14);
  cin>>gestor.codigo;
  gotoxy(46,19);
  cin>>gestor.contrasena;
}

int AdminLogin::VerificarAdmin(GestorVentanas& gestor) {
  if (gestor.codigo == "kevin" && gestor.contrasena == "kevin") {
    return 1;
  }
  else {
    return 2;
  }
}


void AdminLogin::validar_credenciales(GestorVentanas& gestor){
  system("cls");
  int aux = VerificarAdmin(gestor);
  switch (aux){
    case 1:
      //$ INGRESO NORMAL
      gestor.cambiar_ventana(Ventanas::ADMINMAIN);
      break;
    case 2:
      //$ CREDENCIALES INCORRECTAS
      gotoxy(45, 10);
      cout<<"+------------------------------+";
      gotoxy(45, 11);
      cout<<"|   CREDENCIALES INCORRECTAS   |";
      gotoxy(45, 12);
      cout<<"+------------------------------+";
      change_color(244);
      gotoxy(31, 14);
      cout<<"Por favor, no intente ingresar a la cuenta de administrador";
      getch();
      break;
  }
}

void AdminLogin::seleccionar_opcion(GestorVentanas& gestor){
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
    case 1:
      AdminLogin::validar_credenciales(gestor);
      break;
    case 0:
      gestor.cambiar_ventana(Ventanas::MAINWINDOW);
      break;
  }
}

void AdminLogin::main(GestorVentanas& gestor){
  AdminLogin::mostrar();
  AdminLogin::ingresar_credenciales(gestor);
  AdminLogin::seleccionar_opcion(gestor);
  AdminLogin::VerificarAdmin(gestor);
}