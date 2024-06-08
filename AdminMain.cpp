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
    rectangle(50, 22, 35, 2);

    change_color(244);
    gotoxy(53, 3);
    std::cout << "MENU DE ADMIN";

    change_color(240);
    gotoxy(36, 4);
    std::cout << "------------------------------------------------";
    gotoxy(37, 5);
    std::cout << "BIENVENIDO ADMIN";
    gotoxy(40, 7);
    std::cout << "ESCOGE LA ACTIVIDAD QUE DESEA VERIFICAR:";

    change_color(241);
    gotoxy(40, 23);
    std::cout << "UTILIZE LAS FLECHAS PARA SELECCIONAR LAS";
    gotoxy(48, 24);
    std::cout << "OPCIONES (ARRIBA Y ABAJO)";
}

void AdminMain::seleccionar_opcion(GestorVentanas& gestor) {
    int opc = 1, tecla = 72;
    while (tecla != 13) {

        if (tecla == 72 && opc > 1) {
            opc--;
        }
        if (tecla == 80 && opc < 4) {
            opc++;
        }

        switch (opc) {
            //$ LAPTOPS
            case 1:
                change_color(241);
                gotoxy(48, 9);
                std::cout << "+-----------------------+";
                gotoxy(46, 10);
                std::cout << "->|       Verificar       |";
                gotoxy(48, 11);
                std::cout << "+-----------------------+";
                change_color(240);

                gotoxy(48, 12);
                std::cout << "+-----------------------+";
                gotoxy(46, 13);
                std::cout << "  |       Sanciones       |";
                gotoxy(48, 14);
                std::cout << "+-----------------------+";

                gotoxy(48, 15);
                std::cout << "+-----------------------+";
                gotoxy(46, 16);
                std::cout << "  |      Estadisticas     |";
                gotoxy(48, 17);
                std::cout << "+-----------------------+";

                gotoxy(48, 18);
                std::cout << "+-----------------------+";
                gotoxy(46, 19);
                std::cout << "  |         Salir         |";
                gotoxy(48, 20);
                std::cout << "+-----------------------+";
                break;

            //$ CUBICULOS
            case 2:
                gotoxy(48, 9);
                std::cout << "+-----------------------+";
                gotoxy(46, 10);
                std::cout << "  |       Verificar       |";
                gotoxy(48, 11);
                std::cout << "+-----------------------+";

                change_color(241);
                gotoxy(48, 12);
                std::cout << "+-----------------------+";
                gotoxy(46, 13);
                std::cout << "->|       Sanciones       |";
                gotoxy(48, 14);
                std::cout << "+-----------------------+";
                change_color(240);

                gotoxy(48, 15);
                std::cout << "+-----------------------+";
                gotoxy(46, 16);
                std::cout << "  |      Estadisticas     |";
                gotoxy(48, 17);
                std::cout << "+-----------------------+";

                gotoxy(48, 18);
                std::cout << "+-----------------------+";
                gotoxy(46, 19);
                std::cout << "  |         Salir         |";
                gotoxy(48, 20);
                std::cout << "+-----------------------+";
                break;

            //$ RESERVAS HECHAS
            case 3:
                gotoxy(48, 9);
                std::cout << "+-----------------------+";
                gotoxy(46, 10);
                std::cout << "  |       Verificar       |";
                gotoxy(48, 11);
                std::cout << "+-----------------------+";

                gotoxy(48, 12);
                std::cout << "+-----------------------+";
                gotoxy(46, 13);
                std::cout << "  |       Sanciones       |";
                gotoxy(48, 14);
                std::cout << "+-----------------------+";

                change_color(241);

                gotoxy(48, 15);
                std::cout << "+-----------------------+";
                gotoxy(46, 16);
                std::cout << "->|      Estadisticas     |";
                gotoxy(48, 17);
                std::cout << "+-----------------------+";

                change_color(240);
                gotoxy(48, 18);
                std::cout << "+-----------------------+";
                gotoxy(46, 19);
                std::cout << "  |         Salir         |";
                gotoxy(48, 20);
                std::cout << "+-----------------------+";
                break;

            case 4:
                gotoxy(48, 9);
                std::cout << "+-----------------------+";
                gotoxy(46, 10);
                std::cout << "  |       Verificar       |";
                gotoxy(48, 11);
                std::cout << "+-----------------------+";

                gotoxy(48, 12);
                std::cout << "+-----------------------+";
                gotoxy(46, 13);
                std::cout << "  |       Sanciones       |";
                gotoxy(48, 14);
                std::cout << "+-----------------------+";

                gotoxy(48, 15);
                std::cout << "+-----------------------+";
                gotoxy(46, 16);
                std::cout << "  |      Estadisticas     |";
                gotoxy(48, 17);
                std::cout << "+-----------------------+";

                change_color(241);
                gotoxy(48, 18);
                std::cout << "+-----------------------+";
                gotoxy(46, 19);
                std::cout << "->|         Salir         |";
                gotoxy(48, 20);
                std::cout << "+-----------------------+";
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
        case 1:
            gestor.cambiar_ventana(Ventanas::ADMINVERIFICAR);
            break;
        case 2:
            sanciones(gestor);
            break;
        case 3:
            //gestor.cambiar_ventana(Ventanas::ADMINSTATIC);
            filePath = "Estadistica.xlsx";

            // Comando para abrir Excel con el archivo especificado
            command = "start excel \"" + filePath + "\"";

            // Ejecutar el comando
            result = std::system(command.c_str());
            break;
        case 4:
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
    gotoxy(52, 4);
    cout << " NUMERO DE SANCIONES ";

    change_color(240);
    gotoxy(42, 7);
    cout << "Codigo del estudiante: #";
    rectangle(15, 1, 66, 6);

    rectangle(21, 1, 53, 10);
    //+3

    rectangle(15, 1, 43, 22);
    gotoxy(46,23);
    cout << "RESETEAR";

    rectangle(15, 1, 63, 22);
    gotoxy(68,23);
    cout << "ATRAS";
    ingresar_codigo(gestor);
    getch();
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

    change_color(113);
    gotoxy(83,7);
    cout << "CORRECTO";

    change_color(240);
    gotoxy(56,11);
    cout << "N de sancion: #"<<AdminMain::numerosanciones;

    change_color(240);
    hide_cursor();
    confirmar(gestor);
}

void AdminMain::confirmar(GestorVentanas& gestor){
  int opc=1, tecla=75;
  while(tecla!=13){
    switch(tecla){
			case 75:
        change_color(241);
        rectangle(15, 1, 43, 22);
        gotoxy(46,23);
        cout << "RESETEAR";
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
        cout << "RESETEAR";
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