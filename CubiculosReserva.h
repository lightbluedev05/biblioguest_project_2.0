#ifndef CUBICULOSRESERVA_H
#define CUBICULOSRESERVA_H
#include "GestorVentanas.h"
#include <vector>

class GestorVentanas;

class CubiculosReserva {
  public:
    static std::string codigo_cubiculo;
    static std::string horario_cubiculo;
    static std::vector<std::vector<std::string>> horarios_data;
    static std::vector<std::vector<std::string>> reservas_data;
    static std::vector<std::vector<int>> historial;

    //METODOS
    void mostrar();
    void conseguir_data();
    void ingresar_datos(GestorVentanas& gestor);
    void comprobacion_de_datos(GestorVentanas& gestor);
    void ejecutar_reserva(GestorVentanas& gestor, int laptop, int horario);
    
    void main(GestorVentanas& gestor);
};

#endif