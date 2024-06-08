#ifndef LAPTOPRESERVA_H
#define LAPTOPRESERVA_H
#include "GestorVentanas.h"
#include <vector>

class GestorVentanas;

class LaptopReserva {
  public:
    static std::string codigo_laptop;
    static std::string horario_laptop;
    static std::vector<std::vector<std::string>> horarios_data;
    static std::vector<std::vector<std::string>> reservas_data;
    static std::vector<std::vector<int>> historial;
    
    void mostrar();
    void conseguir_data();
    void ingresar_datos(GestorVentanas& gestor);
    void comprobacion_de_datos(GestorVentanas& gestor);
    void ejecutar_reserva(GestorVentanas& gestor, int laptop, int horario);
    
    void main(GestorVentanas& gestor);
};

#endif