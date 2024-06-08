#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H
#include "GestorVentanas.h"

#include "GestorVentanas.h"

class GestorVentanas;

class AdminLogin {
  public:
    //METODOS
    void mostrar();
    void ingresar_credenciales(GestorVentanas& gestor);
    void seleccionar_opcion(GestorVentanas& gestor);
    void validar_credenciales(GestorVentanas& gestor);
    int VerificarAdmin(GestorVentanas& gestor);

    
    void main(GestorVentanas& gestor);
};




#endif