#ifndef LAPTOPMAIN_H
#define LAPTOPMAIN_H
#include "GestorVentanas.h"

class GestorVentanas;

class LaptopMain {
  public:
    void mostrar();
    void listar_laptops();
    void seleccionar_opcion(GestorVentanas& gestor);

    void main(GestorVentanas& gestor);
};


#endif