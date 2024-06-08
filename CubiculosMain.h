#ifndef CUBICULOSMAIN_H
#define CUBICULOSMAIN_H
#include "GestorVentanas.h"

class GestorVentanas;

void escoger_color(int valor);
void pintar_cubiculo(int cubiculo[], int x, int y);

class CubiculosMain {
  public:
    void mostrar();
    void listar_cubiculos();
    void seleccionar_opcion(GestorVentanas& gestor);

    void main(GestorVentanas& gestor);
};


#endif