#include "../include/generar_tabla.h"
#include "../include/jugar.h"
#include "../include/registrar_jugador.h"
#include "../include/mostrar_menus.h"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>


int main() {
  srand((unsigned) time(0));

  const char *LIMPIAR_PANTALLA = "\033[2J\033[1;1H"; 

  char opcion = 0;
  int puntaje_dorado = 0;

  Celda tabla[10][10];
  Jugador jugadores[10];
  int cantidad_jugadores_registrados = 0;
  bool opciones_cargadas[2];

  while (1) {
    std::cout << LIMPIAR_PANTALLA;
    mostrar_menu_principal(opciones_cargadas[0], cantidad_jugadores_registrados, puntaje_dorado);
    std::cin >> opcion;

    if (opcion == '1') {
      generar_tabla(puntaje_dorado, tabla);
      opciones_cargadas[0] = 1;
    }

    if (opcion == '2') {

      if (cantidad_jugadores_registrados == 10) {
        continue;
      }

      std::cout << LIMPIAR_PANTALLA;
      // TODO: moduralizar
      std::string nombre, apellido, usuario;
      std::cout<<"*************** Registrar Usuario **************";
      std::cout<<"\nNombre: ";
      std::cin >> nombre;
      std::cout<<"\nApellido: ";
      std::cin >> apellido;
      std::cout<<"\nNombre de Usuario: ";
      std::cin >> usuario;
      crear_jugador(nombre, apellido, usuario, jugadores, cantidad_jugadores_registrados);
      opciones_cargadas[1] = 1;
    }
    if (opcion == '3') {
      std::cout << LIMPIAR_PANTALLA;
      mostrar_jugadores(jugadores);
      std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    if (opcion == '4') {
      if (opciones_cargadas[0] && cantidad_jugadores_registrados >= 2) {
        jugar(jugadores, tabla, puntaje_dorado);
      }
    }
    if (opcion == '5')
      break;
  }
  return 0;
}
