#ifndef ADMINVERIFICAR_H
#define ADMINVERIFICAR_H
#include "GestorVentanas.h"
#include "string"
#include <vector>

class GestorVentanas;

class AdminVerificar{
  public:

    static char letra;
    static int aux;
    static std::string codigo_encontrado;
    static std::string codigo_estudiante;
    void ingresar_codigo(GestorVentanas& gestor);
    void mostrar(GestorVentanas& gestor);
    void main(GestorVentanas& gestor);
    void validar(GestorVentanas& gestor);
    void opciones(GestorVentanas& gestor);
    void confirmar(GestorVentanas& gestor);
};


#endif