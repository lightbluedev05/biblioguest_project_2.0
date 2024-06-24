#ifndef GESTIONARLAPTOPS_H
#define GESTIONARLAPTOPS_H
#include "GestorVentanas.h"

class GestorVentanas;

class GestionarLaptops{
  public:
    void mostrar();
    void seleccionar_opcion(GestorVentanas& gestor);
    void ver_laptops();
    void cantidad_laptops();
    void anadir_laptop();
    void editar_laptop();
    void eliminar_laptop();
    void estado_laptop();
    void main(GestorVentanas& gestor);
};

#endif