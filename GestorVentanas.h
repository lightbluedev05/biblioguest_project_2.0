#ifndef GESTORVENTANAS_H
#define GESTORVENTANAS_H

#include <string>
//INCLUIR .H DE CADA VENTANA
#include "MainWindow.h"
#include "UserLogin.h"
#include "UserMain.h"
#include "AdminLogin.h"
#include "AdminMain.h"
#include "CubiculosMain.h"
#include "CubiculosReserva.h"
#include "LaptopReserva.h"
#include "LaptopMain.h"
#include "AdminVerificar.h"


//LLAMAR A CADA CLASE DE VENTANA AÑADIDA
class MainWindow;
class UserLogin;
class UserMain;
class AdminLogin;
class AdminMain;
class CubiculosMain;
class CubiculosReserva;
class LaptopMain;
class LaptopReserva;
class AdminVerificar;

//AGREGAR LA VENTANA EN EL ENUM
enum class Ventanas{
  MAINWINDOW,
  USERLOGIN,
  USERMAIN,
  ADMINLOGIN,
  ADMINMAIN,
  CUBICULOSMAIN,
  CUBICULOSRESERVA,
  LAPTOPMAIN,
  LAPTOPRESERVA,
  ADMINVERIFICAR
};

class GestorVentanas {
  public:
    std::string codigo;
    std::string contrasena;
    std::string nombre;
    bool exit=false;

    void iniciar();
    void cambiar_ventana(Ventanas nueva_ventana);
    void terminar_programa();
  private:
    Ventanas ventana_actual=Ventanas::MAINWINDOW;

    //CREAR UN OBJETO DE CADA VENTANA
    MainWindow* main_window;
    UserLogin* user_login;
    UserMain* user_main;
    AdminLogin* admin_login;
    AdminMain* admin_main;
    CubiculosMain* cubiculos_main;
    CubiculosReserva* cubiculos_reserva;
    LaptopMain* laptop_main;
    LaptopReserva* laptop_reserva;
    AdminVerificar* admin_verificar;
};

#endif