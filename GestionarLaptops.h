#ifndef GESTIONARLAPTOPS_H
#define GESTIONARLAPTOPS_H
#include "GestorVentanas.h"

class GestorVentanas;

class GestionarLaptops{
  public:
    void mostrar();
    void seleccionar_opcion(GestorVentanas& gestor);
    void cantidad_laptops();
    void añadir_laptop();
    void editar_laptop();
    void eliminar_laptop();
    void estado_laptop();
    void main(GestorVentanas& gestor);
};

#endif