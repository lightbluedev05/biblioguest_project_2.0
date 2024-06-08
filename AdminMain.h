#ifndef ADMINMAIN_H
#define ADMINMAIN_H
#include "GestorVentanas.h"
#include <string>
class GestorVentanas;

class AdminMain{
  public:
    static std::string numerosanciones;
    static std::vector<std::vector<int>> historial_sanciones;
    static int aux;
    static std::string codigo_estudiante;
    static std::string codigo_encontrado;
    void mostrar(GestorVentanas& gestor);
    void main(GestorVentanas& gestor);
    void seleccionar_opcion(GestorVentanas& gestor);
    void sanciones(GestorVentanas& gestor);
    void ingresar_codigo(GestorVentanas& gestor);
    void confirmar(GestorVentanas& gestor);
};


#endif