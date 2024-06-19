#ifndef ADMINHISTORY_H
#define ADMINHISTORY_H
#include "GestorVentanas.h"
#include <string>
class GestorVentanas;

class AdminHistory{
  public:
    static std::vector<std::vector<std::string>> reservas_historial;
    void mostrar(GestorVentanas& gestor);
    void main(GestorVentanas& gestor);
    void dibujar_tabla(GestorVentanas& gestor);
};


#endif