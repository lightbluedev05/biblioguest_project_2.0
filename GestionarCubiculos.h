#ifndef GESTIONARCUBICULOS_H
#define GESTIONARCUBICULOS_H
#include "GestorVentanas.h"

class GestorVentanas;

class GestionarCubiculos{
  public:
    void mostrar();
    void seleccionar_opcion(GestorVentanas& gestor);
    void ver_cubiculos();
    void cantidad_cubiculos();
    void anadir_cubiculos();
    void editar_cubiculos();
    void eliminar_cubiculos();
    void estado_cubiculos();
    void main(GestorVentanas& gestor);
};

#endif