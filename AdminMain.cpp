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

string confirmadas;
string no_usadas;
vector<vector<string>> history_reservasxd;
vector<vector<string>> solo_ese_alummno;

void AdminMain::mostrar(GestorVentanas& gestor) {
    change_color(112);
    system("cls");
    hide_cursor();

    change_color(240);
    rectangle(80, 18, 20, 5);

    change_color(244);
    gotoxy(53, 6);
    std::cout << "MENU DE ADMIN";

    change_color(240);
    gotoxy(21, 7);
    for(int i=0; i<78; i++){
        cout<<"-";
    }
    gotoxy(22, 8);
    std::cout << "BIENVENIDO ADMIN";
    gotoxy(40, 10);
    std::cout << "ESCOGE LA ACTIVIDAD QUE DESEA VERIFICAR:";

    change_color(241);
    gotoxy(40, 22);
    std::cout << "UTILIZE LAS FLECHAS PARA SELECCIONAR LAS";
    gotoxy(48, 23);
    std::cout << "OPCIONES (ARRIBA Y ABAJO)";
}

void AdminMain::seleccionar_opcion(GestorVentanas& gestor) {
    int opc = 1, tecla = 72;
    int x=1, y=1;
    while (tecla != 13) {
        if(tecla==72 && y>1){
            y--;
        } else if(tecla==80 && y<3){
            y++;
        } else if(tecla==75 && x>1){
            x--;
        } else if(tecla==77 && x<3){
            x++;
        }

        if (x==1 && y==1){
            opc=1;
        } else if (x==2 && y==1){
            opc=2;
        } else if (x==3 && y==1){
            opc=3;
        } else if (x==1 && y==2){
            opc=4;
        } else if (x==2 && y==2){
            opc=5;
        } else if (x==3 && y==2){
            opc=6;
        } else if (x==1 && y==3){
            opc=7;
        } else if (x==2 && y==3){
            opc=8;
        } else if (x==3 && y==3){
            opc=9;
        }

        switch (opc) {
            //$ GESTIONAR LAPTOPS
            case 1:
                change_color(241);
                button(23, 1, 22, 12, "Gestionar Laptops");
                change_color(240);
                button(23, 1, 48, 12, "Gestionar Cubiculos");
                button(23, 1, 74, 12, "Verificar Reserva");
                button(23, 1, 22, 15, "Consultar Sanciones");
                button(23, 1, 48, 15, "Ver Estadisticas");
                button(23, 1, 74, 15, "Ver Historial");
                button(23, 1, 22, 18, "Consultar Alumno");
                button(23, 1, 48, 18, "TOPS");
                button(23, 1, 74, 18, "Salir");
                break;

            //$ GESTIONAR CUBICULOS
            case 2:
                button(23, 1, 22, 12, "Gestionar Laptops");
                change_color(241);
                button(23, 1, 48, 12, "Gestionar Cubiculos");
                change_color(240);
                button(23, 1, 74, 12, "Verificar Reserva");
                button(23, 1, 22, 15, "Consultar Sanciones");
                button(23, 1, 48, 15, "Ver Estadisticas");
                button(23, 1, 74, 15, "Ver Historial");
                button(23, 1, 22, 18, "Consultar Alumno");
                button(23, 1, 48, 18, "TOPS");
                button(23, 1, 74, 18, "Salir");
                break;

            //$ VERIFICAR RESERVAS
            case 3:
                button(23, 1, 22, 12, "Gestionar Laptops");
                button(23, 1, 48, 12, "Gestionar Cubiculos");
                change_color(241);
                button(23, 1, 74, 12, "Verificar Reserva");
                change_color(240);
                button(23, 1, 22, 15, "Consultar Sanciones");
                button(23, 1, 48, 15, "Ver Estadisticas");
                button(23, 1, 74, 15, "Ver Historial");
                button(23, 1, 22, 18, "Consultar Alumno");
                button(23, 1, 48, 18, "TOPS");
                button(23, 1, 74, 18, "Salir");
                break;
            
            //$ CONSULTAR SANCIONES
            case 4:
                button(23, 1, 22, 12, "Gestionar Laptops");
                button(23, 1, 48, 12, "Gestionar Cubiculos");
                button(23, 1, 74, 12, "Verificar Reserva");
                change_color(241);
                button(23, 1, 22, 15, "Consultar Sanciones");
                change_color(240);
                button(23, 1, 48, 15, "Ver Estadisticas");
                button(23, 1, 74, 15, "Ver Historial");
                button(23, 1, 22, 18, "Consultar Alumno");
                button(23, 1, 48, 18, "TOPS");
                button(23, 1, 74, 18, "Salir");
                break;

            //$ VER ESTADISTICAS
            case 5:
                button(23, 1, 22, 12, "Gestionar Laptops");
                button(23, 1, 48, 12, "Gestionar Cubiculos");
                button(23, 1, 74, 12, "Verificar Reserva");
                button(23, 1, 22, 15, "Consultar Sanciones");
                change_color(241);
                button(23, 1, 48, 15, "Ver Estadisticas");
                change_color(240);
                button(23, 1, 74, 15, "Ver Historial");
                button(23, 1, 22, 18, "Consultar Alumno");
                button(23, 1, 48, 18, "TOPS");
                button(23, 1, 74, 18, "Salir");
                break;

            //$ VER HISTORIAL
            case 6:
                button(23, 1, 22, 12, "Gestionar Laptops");
                button(23, 1, 48, 12, "Gestionar Cubiculos");
                button(23, 1, 74, 12, "Verificar Reserva");
                button(23, 1, 22, 15, "Consultar Sanciones");
                button(23, 1, 48, 15, "Ver Estadisticas");
                change_color(241);
                button(23, 1, 74, 15, "Ver Historial");
                change_color(240);
                button(23, 1, 22, 18, "Consultar Alumno");
                button(23, 1, 48, 18, "TOPS");
                button(23, 1, 74, 18, "Salir");
                break;
            
            //$ CONSULTAR ALUMNO
            case 7:
                button(23, 1, 22, 12, "Gestionar Laptops");
                button(23, 1, 48, 12, "Gestionar Cubiculos");
                button(23, 1, 74, 12, "Verificar Reserva");
                button(23, 1, 22, 15, "Consultar Sanciones");
                button(23, 1, 48, 15, "Ver Estadisticas");
                button(23, 1, 74, 15, "Ver Historial");
                change_color(241);
                button(23, 1, 22, 18, "Consultar Alumno");
                change_color(240);
                button(23, 1, 48, 18, "TOPS");
                button(23, 1, 74, 18, "Salir");
                break;

            //$ TOPS
            case 8:
                button(23, 1, 22, 12, "Gestionar Laptops");
                button(23, 1, 48, 12, "Gestionar Cubiculos");
                button(23, 1, 74, 12, "Verificar Reserva");
                button(23, 1, 22, 15, "Consultar Sanciones");
                button(23, 1, 48, 15, "Ver Estadisticas");
                button(23, 1, 74, 15, "Ver Historial");
                button(23, 1, 22, 18, "Consultar Alumno");
                change_color(241);
                button(23, 1, 48, 18, "TOPS");
                change_color(240);
                button(23, 1, 74, 18, "Salir");
                break;
            
            //$ SALIR
            case 9:
                button(23, 1, 22, 12, "Gestionar Laptops");
                button(23, 1, 48, 12, "Gestionar Cubiculos");
                button(23, 1, 74, 12, "Verificar Reserva");
                button(23, 1, 22, 15, "Consultar Sanciones");
                button(23, 1, 48, 15, "Ver Estadisticas");
                button(23, 1, 74, 15, "Ver Historial");
                button(23, 1, 22, 18, "Consultar Alumno");
                button(23, 1, 48, 18, "TOPS");
                change_color(241);
                button(23, 1, 74, 18, "Salir");
                change_color(240);
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
            gestor.cambiar_ventana(Ventanas::GESTIONARCUBICULOS);
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

        //$ VER HISTORIAL
        case 6:
            gestor.cambiar_ventana(Ventanas::ADMINHISTORY);
            break;
        
        //$ CONSULTAR ALUMNO
        case 7:
            AdminMain::buscaralumno(gestor);
            break;
        
        //$ TOPS
        case 8:
            gestor.cambiar_ventana(Ventanas::ADMININFORME);
            break;

        //$ SALIR
        case 9:
            gestor.cambiar_ventana(Ventanas::MAINWINDOW);
            break;
    }
}

string cantidad(string filtro){
    vector<vector<string>> conteo;
    conteo.clear();
    for (int i = 0; i < solo_ese_alummno.size(); i++) {
        string codigoAL = solo_ese_alummno[i][2];
        bool encontrado = false;
        if(solo_ese_alummno[i][7]==filtro){
          for (int j = 0; j < conteo.size(); j++) {
              if (conteo[j][0] == codigoAL) {
                  int cantidad_reservas = stoi(conteo[j][1]);
                  cantidad_reservas++;
                  conteo[j][1] = to_string(cantidad_reservas);
                  encontrado = true;
                  break;
              }
          }
          if (!encontrado) {
              conteo.push_back({AdminMain::codigo_estudiante, "1"});
          }
        }
    }

    for(int i = 0; i < conteo.size(); i++){
        if(conteo[i][0] == AdminMain::codigo_estudiante){
            return conteo[i][1];
        }
    }

    return "0";
}

void AdminMain::buscaralumno(GestorVentanas& gestor){
    change_color(112);
    system("cls");
    show_cursor();

    change_color(240);
    rectangle(67, 22, 27, 3);

    change_color(244);
    gotoxy(52, 4);
    cout << " CONSULTAR ALUMNO ";

    change_color(240);
    gotoxy(42, 7);
    cout << "Codigo del estudiante: #";
    rectangle(15, 1, 66, 6);

    vector<vector<string>> user;

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

    AdminMain::codigo_encontrado = "no";
    string nombre;
    string contra;
    int contador = 0;

    do {
        if (contador > 0) {
            change_color(244);
            gotoxy(85,7);
            cout << "ERROR";
            change_color(240);
        }
        if(contador == 3){
            change_color(244);
            gotoxy(47,15);
            cout<<"Volviendo al menu principal...";
            change_color(240);
            getch();
            gestor.cambiar_ventana(Ventanas::ADMINMAIN);
            return;
        }
        gotoxy(67,7);
        cout << "             ";
        gotoxy(67,7);
        cin >> AdminMain::codigo_estudiante;

        for (int i = 0; i < user.size(); i++) {
            if (user[i][0] == AdminMain::codigo_estudiante) {
                nombre = user[i][2];
                contra = user[i][1];
                AdminMain::codigo_encontrado = "si";
                AdminMain::aux = i;
                break;
            }
        }
        contador++;
    } while (AdminMain::codigo_encontrado == "no");
    int x;
    x = 28+((65-(nombre.length()+3))/2);

    ifstream file_5("reservas_history.csv");
    string linea_5;

    history_reservasxd.clear();

    // Leer datos desde el archivo CSV y almacenar en history_reservas
    while (getline(file_5, linea_5)) {
        vector<string> reservas;
        string reserva;
        stringstream ss(linea_5);

        while (getline(ss, reserva, ',')) {
            reservas.push_back(reserva);
        }

        history_reservasxd.push_back(reservas);
    }

    file_5.close();

    for (int i = 0; i < history_reservasxd.size(); i++) {
        if (history_reservasxd[i][2] == AdminMain::codigo_estudiante) {
            solo_ese_alummno.push_back(history_reservasxd[i]);
        }
    }
    string contra_aste(contra.length(), '*');
    button(nombre.length()+3, 1, x, 10, nombre);
    hide_cursor();
    gotoxy(40,15);
    change_color(244);
    cout << "Reservas Confirmadas  : ";change_color(240);cout<<cantidad("SI");
    gotoxy(40,17);
    change_color(244);
    cout << "Reservas No Usadas    : ";change_color(240);cout<<cantidad("NO");
    gotoxy(40,19);
    change_color(244);
    cout << "Contrasena : ";change_color(240);cout<<contra_aste;
    int opc=1, tecla=75;
    string nuevacontra;
    while(tecla!=13 || opc == 1){
        if(tecla==75 && opc>1){
            opc--;
        } else if(tecla==77 && opc<3){
            opc++;
        }

        switch(opc){
            case 1:
                change_color(241);
                button(18, 1, 33, 20, "VER CONTRASENA");
                change_color(240);
                button(20, 1, 53, 20, "CAMBIAR CONTRASENA");
                button(13, 1, 75, 20, "SALIR");
                break;
            case 2:
                button(18, 1, 33, 20, "VER CONTRASENA");
                change_color(241);
                button(20, 1, 53, 20, "CAMBIAR CONTRASENA");
                change_color(240);
                button(13, 1, 75, 20, "SALIR");
                break;
            case 3:
                button(18, 1, 33, 20, "VER CONTRASENA");
                button(20, 1, 53, 20, "CAMBIAR CONTRASENA");
                change_color(241);
                button(13, 1, 75, 20, "SALIR");
                change_color(240);
                break;
        }
        tecla = _getch();

        if(tecla==13 && opc == 1){
            gotoxy(40,19);
            change_color(240);
            cout<<"                                        ";
            gotoxy(40,19);
            change_color(244);
            cout << "Contrasena : ";change_color(240);cout<<contra;            
        }
    }

    switch(opc){
        case 2:{
            change_color(240);
            gotoxy(38,13);
            cout << "Si te confundiste escribe ";change_color(244);cout<<"SALIR";change_color(240);cout<<" para cancelar";
            change_color(244);
            gotoxy(40,24);
            cout << "Nueva Contra --> ";
            change_color(240);
            button(23, 1, 58, 23, "                     ");
            gotoxy(60,24);
            show_cursor();
            cin >> nuevacontra;
            if(nuevacontra != "SALIR"){
                user[AdminMain::aux][1] = nuevacontra;
                ofstream archivoSalidas("datos.txt");
                
                for (int i = 0; i < user.size(); ++i) {
                    archivoSalidas << user[i][0] << " " << user[i][1] << user[i][2];
                    if(i != user.size() - 1){
                        archivoSalidas << "\n";
                    }
                }
                
                archivoSalidas.close();
            }
            gestor.cambiar_ventana(Ventanas::ADMINMAIN);}
            break;
        case 3:
            gestor.cambiar_ventana(Ventanas::ADMINMAIN);
            break;
    }
    hide_cursor();
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
    button(14, 1, 33, 19, "ANADIR UNA");
    button(14, 1, 53, 19, "RESETEAR");
    button(13, 1, 73, 19, "ATRAS");

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
        if(contador == 3){
            change_color(244);
            gotoxy(47,15);
            cout<<"Volviendo al menu principal...";
            change_color(240);
            getch();
            gestor.cambiar_ventana(Ventanas::ADMINMAIN);
            return;
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
    int opc=1, tecla=75;
    while(tecla!=13){
        if(tecla==75 && opc>1){
            opc--;
        } else if(tecla==77 && opc<3){
            opc++;
        }

        switch(opc){
            case 1:
                change_color(241);
                button(14, 1, 33, 19, "ANADIR UNA");
                change_color(240);
                button(14, 1, 53, 19, "RESETEAR");
                button(13, 1, 73, 19, "ATRAS");
                break;
            case 2:
                button(14, 1, 33, 19, "ANADIR UNA");
                change_color(241);
                button(14, 1, 53, 19, "RESETEAR");
                change_color(240);
                button(13, 1, 73, 19, "ATRAS");
                break;
            case 3:
                button(14, 1, 33, 19, "ANADIR UNA");
                button(14, 1, 53, 19, "RESETEAR");
                change_color(241);
                button(13, 1, 73, 19, "ATRAS");
                change_color(240);
                break;
        }
        tecla = _getch();
    }

   switch(opc) {
        case 1: {
            for (int i = 0; i < UserMain::historial_sanciones.size(); i++){
                if (std::to_string(UserMain::historial_sanciones[i][0]) == AdminMain::codigo_estudiante && UserMain::historial_sanciones[i][1] < 3) {
                    UserMain::historial_sanciones[i][1] +=1;
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
        case 2: {
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
        case 3:
        gestor.cambiar_ventana(Ventanas::ADMINMAIN);
        break;
  }
}

void AdminMain::main(GestorVentanas& gestor) {
    AdminMain::mostrar(gestor);
    AdminMain::seleccionar_opcion(gestor);
}