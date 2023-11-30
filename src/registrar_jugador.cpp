#include "../include/registrar_jugador.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

bool comparar_por_apellido(Jugador a, Jugador b) { if (a.apellido < b.apellido) {
    return 1;
  } else {
    return 0;
  }
}

bool jugador_existe(std::string usuario, 
                   Jugador jugadores[10]) {
  for(int i = 0; i < 10; i++) {
    if(jugadores[i].usuario == usuario) {
      return true;
    }
  }
  return false;
}

void ordenar_por_apellido(Jugador jugadores[10], int cantidad_de_jugadores) {
  int i, j, indice_minimo;
  for (i = 0; i < cantidad_de_jugadores; i++) {
    indice_minimo = i;
    for (j = i+1; j < cantidad_de_jugadores; j++) {
      if (jugadores[j].apellido < jugadores[indice_minimo].apellido) {
        indice_minimo = j;
      }
    }
    Jugador temp = jugadores[indice_minimo];
    jugadores[indice_minimo] = jugadores[i];
    jugadores[i] = temp;
  }
}

/**
* Agrega un jugador al arreglo
*
* Si el jugador existe, no se lo agrega (busca por attributo *usuario*)
*
*/
void crear_jugador(std::string nombre, std::string apellido, std::string usuario,
                 Jugador jugadores[10], int &posicion_ultimo_jugador) {

  if(jugador_existe(usuario, jugadores)) {
    std::cout<<"USUARIO YA EXISTENTE\n"; 
    return; 
  }

  jugadores[posicion_ultimo_jugador] = Jugador {nombre, apellido, usuario};
  posicion_ultimo_jugador += 1;

  ordenar_por_apellido(jugadores, posicion_ultimo_jugador);
}

void mostrar_jugadores(Jugador jugadores[10]) {
  std::cout<<"Lista de Jugadores: \n";
  for (int i = 0; i < 10; i++) {
    std::cout << "Usuario: " << jugadores[i].usuario << "\n\t";
    std::cout << "Nombre: " << jugadores[i].nombre << "\n\t";
    std::cout << "Apellido: " << jugadores[i].apellido << "\n";
  }
}
