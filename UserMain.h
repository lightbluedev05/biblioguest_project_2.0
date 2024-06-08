#ifndef USERMAIN_H
#define USERMAIN_H
#include "GestorVentanas.h"
#include <vector>
#include <string>

class GestorVentanas;

class UserMain{
  public:
    static std::string sanciones;
    static std::vector<std::vector<int>> historial;
    static std::string horario_laptop;
    static std::string horario_cubiculo;
    static std::vector<std::vector<int>> historial_sanciones;
    void mostrar(GestorVentanas& gestor);
    void mostrar_reservas(GestorVentanas& gestor);
    void cancelar_reserva(GestorVentanas& gestor);
    void seleccionar_opcion(GestorVentanas& gestor);

    void main(GestorVentanas& gestor);
};


#endif