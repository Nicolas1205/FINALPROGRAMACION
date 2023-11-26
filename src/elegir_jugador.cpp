#include "../include/elegir_jugador.h"
#include "../include/registrar_jugador.h"
#include <iostream>
#include <string>

/**
* Busca un jugador en el arreglo jugadores y lo agrega a los jugadores en juego 
*
* devuelve verdadero si ha sido agregado correctamente
*
* devuelve falso, si el jugador ya ha sido seleccionado para jugar o el jugador no existe
*
*/
bool buscar_jugador(std::string usuario, Jugador jugadores[10],

                   Jugador jugadores_en_juego[2], int posicion) {

  for (int i = 0; i < 10; i++) {
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

/**
* Elige a los dos jugadores para jugar 
*
* Devuelve un vector con los jugadores seleccionados
*/
void elegir_jugadores(Jugador jugadores[10], Jugador jugadores_en_juego[2]) {

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
}
