#include "../include/chose_player.h"
#include "../include/register_player.h"
#include <iostream>
#include <string>

bool search_player(std::string usuario, std::vector<Jugador> &jugadores,
                   std::vector<Jugador> &jugadores_en_juego, int posicion) {

  for (int i = 0; i < jugadores.size(); i++) {
    if (jugadores[i].usuario == usuario) {
      if (!jugadores[i].jugando ) {
        jugadores[i].jugando = true;
        jugadores_en_juego[posicion].nombre = jugadores[i].nombre;
        jugadores_en_juego[posicion].apellido = jugadores[i].apellido;
        jugadores_en_juego[posicion].usuario = jugadores[i].usuario;
        return true;
      } else if (jugadores[i].jugando) {
        puts("ESTE JUGADOR YA FUE SELECCIONADO");
        return false;
      }
    }
  }
  puts("ESTE JUGADOR NO ESTA REGISTRADO");
  return false;
}

std::vector<Jugador> chose_players() {

  std::vector<Jugador> jugadores = obtener_datos_de_jugadores();
  std::vector<Jugador> jugadores_en_juego(2);

  for (int posicion = 0; posicion < 2; posicion++) {
    bool seleccionado = false;
    while (!seleccionado) {

      printf("SELECIONAR JUGADORES\n");
      printf("Ingrese username del jugador %d: ", posicion + 1);
      std::string usuario;
      std::cin >> usuario;
      if (search_player(usuario, jugadores, jugadores_en_juego, posicion)) {
        seleccionado = true;
        std::cout << jugadores_en_juego[posicion].usuario<< " fue seleccionado!\n";
      }
    }
  }

  return jugadores_en_juego;
}
