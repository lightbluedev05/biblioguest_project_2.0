#ifndef ADMININFORME_H
#define ADMININFORME_H
#include "GestorVentanas.h"
#include <string>
class GestorVentanas;

class AdminInforme{
  public:
    void mostrar(GestorVentanas& gestor);
    void main(GestorVentanas& gestor);
    void dibujar(GestorVentanas& gestor);
};


#endif