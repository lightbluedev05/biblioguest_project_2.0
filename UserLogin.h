#ifndef USERLOGIN_H
#define USERLOGIN_H
#include "GestorVentanas.h"
#include <vector>
#include <string>
class GestorVentanas;

class UserLogin {
  public:
    //METODOS
    void mostrar();
    void ingresar_credenciales(GestorVentanas& gestor);
    void seleccionar_opcion(GestorVentanas& gestor);
    void validar_credenciales(GestorVentanas& gestor);
    static std::vector<std::vector<int>> historial_sanciones;
    static std::string sanciones;
    
    void main(GestorVentanas& gestor);
};


#endif