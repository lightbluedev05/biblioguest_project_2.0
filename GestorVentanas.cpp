#include "GestorVentanas.h"
#include "functions.h"
#include <iostream>


void GestorVentanas::iniciar(){
  hide_cursor();
  while(!GestorVentanas::exit){
    switch(ventana_actual){
      //AGREGAR CADA CASO DE VENTANA
      case Ventanas::MAINWINDOW:
        main_window->main(*this);
        break;
      case Ventanas::USERLOGIN:
        user_login->main(*this);
        break;
      case Ventanas::USERMAIN:
        user_main->main(*this);
        break;
      case Ventanas::LAPTOPMAIN:
        laptop_main->main(*this);
        break;
      case Ventanas::CUBICULOSMAIN:
        cubiculos_main->main(*this);
        break;
      case Ventanas::ADMINLOGIN:
        admin_login->main(*this);
        break;
      case Ventanas::ADMINMAIN:
        admin_main->main(*this);
        break;
      case Ventanas::CUBICULOSRESERVA:
        cubiculos_reserva->main(*this);
        break;
      case Ventanas::LAPTOPRESERVA:
        laptop_reserva->main(*this);
        break;
      case Ventanas::ADMINVERIFICAR:
        admin_verificar->main(*this);
        break;
    }
  }
}

void GestorVentanas::cambiar_ventana(Ventanas nueva_ventana){
  ventana_actual=nueva_ventana;
}

void GestorVentanas::terminar_programa(){
  GestorVentanas::exit=true;
}