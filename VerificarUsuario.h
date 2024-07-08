#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "GestorVentanas.h"
#include "functions.h"

using namespace std;

// Definición de estructuras y variables globales
vector<vector<string>> users; // Vector que almacena los usuarios como vectores de strings

// Función para verificar si un usuario existe y la contraseña es correcta
bool verificar(const string& cod_ingresado, const string& contra_ingresado, const vector<vector<string>>& users) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i][0] == cod_ingresado && users[i][1] == contra_ingresado) {
            return true;
        }
    }
    return false;
}

// Función para guardar los datos en el archivo datos.txt
void guardardatos(const vector<vector<string>>& users) {
    ofstream archivoSalida("datos.txt");

    for (int i = 0; i < users.size(); ++i) {
        archivoSalida << users[i][0] << " " << users[i][1] << users[i][2];
        if(i != users.size() - 1){
            archivoSalida << "\n";
        }
    }

    archivoSalida.close();
}

// Función para verificar si el código ingresado es nuevo
bool verificarnuevo(const string& cod_ingresado, const vector<vector<string>>& users) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i][0] == cod_ingresado && users[i][1] == "ODNCXASODXASLO15533") {
            return true;
        }
    }
    return false;
}

// Función para verificar si el código ingresado es válido (matrícula)
bool vericarmatricula(const string& cod_ingresado, const vector<vector<string>>& users) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i][0] == cod_ingresado) {
            return true;
        }
    }
    return false;
}

// Función para escribir un mensaje con el nombre del usuario
void escribir(const string& n) {
    int length = n.length();
    
    cout << "\n\n\n\t\t+-----------------------";
    for (int i = 0; i < length; i++) {
        cout << "-";
    }
    cout << "+" << endl;
    
    cout << "\t\t| Bienvenido al sistema " << n << " |" << endl;
    
    cout << "\t\t+-----------------------";
    for (int i = 0; i < length; i++) {
        cout << "-";
    }
    cout << "+" << endl;
    cout << "\t\tDale ENTER para continuar" << endl;
}

// Función para verificar el usuario ingresado
int VerificarUsuario(const string& cod_ingresado, const string& contra_ingresado, GestorVentanas& gestor) {
    // Cargar usuarios desde el archivo datos.txt a users
    users.clear();
	ifstream archivo("datos.txt");
	string line;

	while (getline(archivo, line)) {
		istringstream iss(line);
		vector<string> u;
		string codigo, contra, nombre_completo;

		// Leer cada elemento de la línea
		iss >> codigo >> contra;
		getline(iss, nombre_completo); // Esto captura el resto de la línea como nombre completo

		// Agregar al vector de usuarios
		u.push_back(codigo);
		u.push_back(contra);
		u.push_back(nombre_completo);

		users.push_back(u);
	}
	archivo.close();

    int aux = -1;
    int aux2 = 0;

    if (verificar(cod_ingresado, contra_ingresado, users)) {
        // Ingreso normal
        for (int i = 0; i < users.size(); ++i) {
            if (users[i][0] == cod_ingresado) {
                aux = i;
                break;
            }
        }
        aux2 = 1; // Usuario y contraseña correctos
        gestor.nombre = users[aux][2]; // Asignar nombre al gestor
    } else {
        if (verificarnuevo(cod_ingresado, users)) {
            // Nuevo matriculado
            for (int i = 0; i < users.size(); ++i) {
                if (users[i][0] == cod_ingresado) {
                    aux = i;
                    break;
                }
            }
            users[aux][1] = contra_ingresado; // Actualizar contraseña en los datos
            guardardatos(users); // Guardar cambios en datos.txt

            aux2 = 2; // Usuario nuevo matriculado
            gestor.nombre = users[aux][2]; // Asignar nombre al gestor
        } else {
            if (vericarmatricula(cod_ingresado, users)) {
                aux2 = 3; // Contraseña incorrecta
            } else {
                aux2 = 4; // No es alumno
            }
        }
    }

    return aux2;
}