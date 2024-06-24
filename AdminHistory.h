#ifndef ADMINHISTORY_H
#define ADMINHISTORY_H
#include "GestorVentanas.h"
#include <string>
class GestorVentanas;

class AdminHistory{
  public:
    static std::vector<std::vector<std::string>> reservas_historial;
    static std::vector<std::vector<std::string>> filtro;
    static std::vector<std::vector<std::string>> aux;
    void mostrar(GestorVentanas& gestor);
    void main(GestorVentanas& gestor);
    void dibujar_tabla(GestorVentanas& gestor);
    void jalar_datos(GestorVentanas& gestor);
    void aplicar_filtro(GestorVentanas& gestor);
    void elegir_opcion(GestorVentanas& gestor);
    void buscar_salir_ver(GestorVentanas& gestor);
    static int op;
    static std::string buscar;
    static int auxpase;
    static int aux2;
};


#endif