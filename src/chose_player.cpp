#include "../include/chose_player.h"
#include "../include/register_player.h"
#include <iostream>
#include <string>

bool buscar_jugador(std::string usuario, std::vector<Jugador> &jugadores,
                   std::vector<Jugador> &jugadores_en_juego, int posicion) {

  for (int i = 0; i < jugadores.size(); i++) {
    if (jugadores[i].usuario == usuario) {
      if (jugadores[i].jugando == false ) {
        jugadores[i].jugando = true;
        jugadores_en_juego[posicion] = jugadores[i];
        return true;
      } else {
        std::cout<<"ESTE JUGADOR YA FUE SELECCIONADO";
        return false;
      }
    }
  }
  std::cout<<"ESTE JUGADOR NO ESTA REGISTRADO";
  return false;
}

std::vector<Jugador> elegir_jugadores(std::vector<Jugador> &jugadores) {

  std::vector<Jugador> jugadores_en_juego(2);

  for (int posicion = 0; posicion < 2; posicion++) {
    bool seleccionado = false;
    // TODO: moduralizar
    while (!seleccionado) {
      std::cout<<"SELECIONAR JUGADORES\n";
      std::cout<<"Ingrese username del jugador "<<posicion+1<<": ";
      std::string usuario;
      std::cin >> usuario;
      if (buscar_jugador(usuario, jugadores, jugadores_en_juego, posicion)) { // TODO: Side-effect
        seleccionado = true;
        std::cout << jugadores_en_juego[posicion].usuario<< " fue seleccionado!\n";
      }
    }
  }

  return jugadores_en_juego;
}
