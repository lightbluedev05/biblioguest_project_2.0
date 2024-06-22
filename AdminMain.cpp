#include "GestorVentanas.h"
#include "AdminMain.h"
#include "functions.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string AdminMain::codigo_encontrado;
string AdminMain::codigo_estudiante;
string AdminMain::numerosanciones;
int AdminMain::aux;
vector<vector<int>> AdminMain::historial_sanciones;

void AdminMain::mostrar(GestorVentanas& gestor) {
    change_color(112);
    system("cls");
    hide_cursor();

    change_color(240);
    rectangle(50, 27, 35, 1);

    change_color(244);
    gotoxy(53, 2);
    std::cout << "MENU DE ADMIN";

    change_color(240);
    gotoxy(36, 3);
    std::cout << "------------------------------------------------";
    gotoxy(37, 4);
    std::cout << "BIENVENIDO ADMIN";
    gotoxy(40, 6);
    std::cout << "ESCOGE LA ACTIVIDAD QUE DESEA VERIFICAR:";

    change_color(241);
    gotoxy(40, 27);
    std::cout << "UTILIZE LAS FLECHAS PARA SELECCIONAR LAS";
    gotoxy(48, 28);
    std::cout << "OPCIONES (ARRIBA Y ABAJO)";
}

void AdminMain::seleccionar_opcion(GestorVentanas& gestor) {
    int opc = 1, tecla = 72;
    while (tecla != 13) {

        if (tecla == 72 && opc > 1) {
            opc--;
        }
        if (tecla == 80 && opc < 6) {
            opc++;
        }

        switch (opc) {
            //$ GESTIONAR LAPTOPS
            case 1:
                change_color(241);
                button(25, 1, 48, 8, "Gestionar Laptops");
                change_color(240);

                button(25, 1, 48, 11, "Gestionar Cubiculos");
                button(25, 1, 48, 14, "Verificar Reserva");
                button(25, 1, 48, 17, "Consultar Sanciones");
                button(25, 1, 48, 20, "Ver Estadisticas");
                button(25, 1, 48, 23, "Salir");
                break;

            //$ GESTIONAR CUBICULOS
            case 2:
                button(25, 1, 48, 8, "Gestionar Laptops");

                change_color(241);
                button(25, 1, 48, 11, "Gestionar Cubiculos");
                change_color(240);

                button(25, 1, 48, 14, "Verificar Reserva");
                button(25, 1, 48, 17, "Consultar Sanciones");
                button(25, 1, 48, 20, "Ver Estadisticas");
                button(25, 1, 48, 23, "Salir");
                break;

            //$ VERIFICAR RESERVAS
            case 3:
                button(25, 1, 48, 8, "Gestionar Laptops");
                button(25, 1, 48, 11, "Gestionar Cubiculos");

                change_color(241);
                button(25, 1, 48, 14, "Verificar Reserva");
                change_color(240);

                button(25, 1, 48, 17, "Consultar Sanciones");
                button(25, 1, 48, 20, "Ver Estadisticas");
                button(25, 1, 48, 23, "Salir");
                break;
            
            //$ CONSULTAR SANCIONES
            case 4:
                button(25, 1, 48, 8, "Gestionar Laptops");
                button(25, 1, 48, 11, "Gestionar Cubiculos");
                button(25, 1, 48, 14, "Verificar Reserva");

                change_color(241);
                button(25, 1, 48, 17, "Consultar Sanciones");
                change_color(240);

                button(25, 1, 48, 20, "Ver Estadisticas");
                button(25, 1, 48, 23, "Salir");
                break;

            //$ VER ESTADISTICAS
            case 5:
                button(25, 1, 48, 8, "Gestionar Laptops");
                button(25, 1, 48, 11, "Gestionar Cubiculos");
                button(25, 1, 48, 14, "Verificar Reserva");
                button(25, 1, 48, 17, "Consultar Sanciones");

                change_color(241);
                button(25, 1, 48, 20, "Ver Estadisticas");
                change_color(240);

                button(25, 1, 48, 23, "Salir");
                break;

            //$ SALIR
            case 6:
                button(25, 1, 48, 8, "Gestionar Laptops");
                button(25, 1, 48, 11, "Gestionar Cubiculos");
                button(25, 1, 48, 14, "Verificar Reserva");
                button(25, 1, 48, 17, "Consultar Sanciones");
                button(25, 1, 48, 20, "Ver Estadisticas");

                change_color(241);
                button(25, 1, 48, 23, "Salir");
                change_color(240);
                break;
        }

        tecla = _getch();
    }

    // Declarar variables antes del switch
    std::string filePath;
    std::string command;
    int result;

    switch (opc) {
        //$ GESTIONAR LAPTOPS
        case 1:
            gestor.cambiar_ventana(Ventanas::GESTIONARLAPTOPS);
            break;

        //$ GESTIONAR CUBICULOS
        case 2:
            break;

        //$ VERIFICAR RESERVAS
        case 3:
            gestor.cambiar_ventana(Ventanas::ADMINVERIFICAR);
            break;

        //$ CONSULTAR SANCIONES
        case 4:
            sanciones(gestor);
            break;

        //$ VER ESTADISTICAS
        case 5:
            //gestor.cambiar_ventana(Ventanas::ADMINSTATIC);
            filePath = "Estadistica.xlsx";

            // Comando para abrir Excel con el archivo especificado
            command = "start excel \"" + filePath + "\"";

            // Ejecutar el comando
            result = std::system(command.c_str());
            break;

        //$ SALIR
        case 6:
            gestor.cambiar_ventana(Ventanas::MAINWINDOW);
            break;
    }
}
//dasd
void AdminMain::sanciones(GestorVentanas& gestor){
    change_color(112);
    system("cls");
    show_cursor();

    change_color(240);
    rectangle(67, 22, 27, 3);

    change_color(244);
    gotoxy(50, 4);
    cout << " NUMERO DE SANCIONES ";

    change_color(240);
    gotoxy(42, 7);
    cout << "Codigo del estudiante: #";
    rectangle(15, 1, 66, 6);

    rectangle(22, 1, 49, 10);
    //+3

    rectangle(15, 1, 43, 19);
    gotoxy(46,20);
    cout << "RESETEAR";

    rectangle(15, 1, 63, 19);
    gotoxy(68,20);
    cout << "ATRAS";
    ingresar_codigo(gestor);
}
//a
void AdminMain::ingresar_codigo(GestorVentanas& gestor) {
    ifstream file_sanciones("sanciones.csv");
    string linea_h;

    UserMain::historial_sanciones.clear();

    // Leer el historial de sanciones desde el archivo CSV
    while(getline(file_sanciones, linea_h)) {
        vector<int> history_sanciones;
        string valor1;
        stringstream ss3(linea_h);

        while(getline(ss3, valor1, ',')) {
            history_sanciones.push_back(stoi(valor1));
        }
        UserMain::historial_sanciones.push_back(history_sanciones);
    }
    file_sanciones.close();

    AdminMain::codigo_encontrado = "no";
    int contador = 0;

    do {
        if (contador > 0) {
            change_color(244);
            gotoxy(85,7);
            cout << "ERROR";
            change_color(240);
        }
        gotoxy(67,7);
        cout << "             ";
        gotoxy(67,7);
        cin >> AdminMain::codigo_estudiante;

        for (int i = 0; i < UserMain::historial_sanciones.size(); i++) {
            if (std::to_string(UserMain::historial_sanciones[i][0]) == AdminMain::codigo_estudiante) {
                AdminMain::numerosanciones = std::to_string(UserMain::historial_sanciones[i][1]);
                AdminMain::codigo_encontrado = "si";
                AdminMain::aux = i;
                break;
            }
        }
        contador++;
    } while (AdminMain::codigo_encontrado == "no");

    change_color(250);
    gotoxy(83,7);
    cout << "CORRECTO";

    change_color(240);
    gotoxy(52,11);
    cout << "N de sancion: #"<<AdminMain::numerosanciones;

    change_color(240);
    hide_cursor();
    confirmar(gestor);
}

void AdminMain::confirmar(GestorVentanas& gestor){
  int opc=1, tecla=75;
    change_color(244);
    gotoxy(45, 14);
    std::cout<<"RESETEAR :";
    gotoxy(45, 17);
    std::cout<<"ATRAS    : ";
    change_color(240);
    gotoxy(56,14);
    std::cout<<"Reiniciar la cantidad";
    gotoxy(56,15);
    std::cout<<"de sanciones";
    gotoxy(56,17);
    std::cout<<"Salir al menu principal";
    change_color(241);
    gotoxy(40, 23);
    std::cout << "UTILIZE LAS FLECHAS PARA SELECCIONAR LAS";
    gotoxy(45, 24);
    std::cout << "OPCIONES (IZQUIERDA Y DERECHA)";
  while(tecla!=13){
    switch(tecla){
			case 75:
        change_color(241);
        rectangle(15, 1, 43, 19);
        gotoxy(46,20);
        cout << "RESETEAR";
        change_color(240);

        rectangle(15, 1, 63, 19);
        gotoxy(68,20);
        cout << "ATRAS";

				opc=0;
				break;
			case 77:
        rectangle(15, 1, 43, 19);
        gotoxy(46,20);
        cout << "RESETEAR";

        change_color(241);
        rectangle(15, 1, 63, 19);
        gotoxy(68,20);
        cout << "ATRAS";
        change_color(240);
				
				opc=1;
				break;
		}
    tecla = _getch();
  }

   switch(opc) {
      case 0: {
        for (int i = 0; i < UserMain::historial_sanciones.size(); i++){
          if (std::to_string(UserMain::historial_sanciones[i][0]) == AdminMain::codigo_estudiante) {
            UserMain::historial_sanciones[i][1] =0;
            break;
          }
        }

        ofstream file_sanciones("sanciones.csv");
        for (int i = 0; i < UserMain::historial_sanciones.size(); i++){
            file_sanciones << UserMain::historial_sanciones[i][0] << "," << UserMain::historial_sanciones[i][1] << endl;
        }
        file_sanciones.close();
          gestor.cambiar_ventana(Ventanas::ADMINMAIN);
          break;
      }
    case 1:
      gestor.cambiar_ventana(Ventanas::ADMINMAIN);
      break;
  }
}

void AdminMain::main(GestorVentanas& gestor) {
    AdminMain::mostrar(gestor);
    AdminMain::seleccionar_opcion(gestor);
}