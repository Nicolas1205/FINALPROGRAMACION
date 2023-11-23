#include "../include/registrar_jugador.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

bool comparar_por_apellido(Jugador a, Jugador b) {
  if (a.apellido < b.apellido) {
    return 1;
  } else {
    return 0;
  }
}

bool jugador_existe(std::string usuario, 
                    std::vector<Jugador> &jugadores) {
  for(int i = 0; i < jugadores.size(); i++) {
    if(jugadores[i].usuario == usuario) {
      return true;
    }
  }
  return false;
}

void ordenar_por_apellido(std::vector<Jugador> &jugadores) {
  sort(jugadores.begin(), jugadores.end(), comparar_por_apellido);
}

/**
* Agrega un jugador al arreglo
*
* Si el jugador existe, no se lo agrega (busca por attributo *usuario*)
*
*/
void crear_jugador(std::string nombre, std::string apellido, std::string usuario,
                 std::vector<Jugador> &jugadores) {

  if(jugador_existe(usuario, jugadores)) {
    std::cout<<"USUARIO YA EXISTENTE\n"; 
    return; 
  }
  jugadores.push_back(Jugador {nombre, apellido, usuario});
  ordenar_por_apellido(jugadores);
}

void mostrar_jugadores(std::vector<Jugador> &jugadores) {
  for (int i = 0; i < jugadores.size(); i++) {
    std::cout << "Usuario: " << jugadores[i].usuario << "\n\t";
    std::cout << "Nombre: " << jugadores[i].nombre << "\n\t";
    std::cout << "Apellido: " << jugadores[i].apellido << "\n";
  }
}
