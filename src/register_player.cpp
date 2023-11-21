#include "../include/register_player.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

std::vector<Jugador> obtener_datos_de_jugadores() {
  // TODO: Nothing at all is all perfect

  std::ifstream i("../data/players.txt");

  int players_sz;

  i >> players_sz;

  if (!players_sz) {
    std::vector<Jugador> players_data;
    return players_data;
  }

  std::vector<Jugador> players_data(players_sz);

  for (int iter = 0; iter < players_sz; iter++) {
    i >> players_data[iter].usuario >> players_data[iter].nombre>>
        players_data[iter].apellido;
  }

  return players_data;
}

bool comparar_por_apellido(Jugador a, Jugador b) {
  if (a.apellido < b.apellido) {
    return 1;
  } else
    return 0;
}

void crear_jugador(std::string nombre, std::string apellido, std::string usuario,
                 std::vector<Jugador> &jugadores) {

  std::ofstream o("../data/players.txt");

  for (int i = 0; i < jugadores.size(); i++) {
    if (jugadores[i].usuario == usuario) {
      std::cout << "USUARIO YA EXISTENTE\n";
      o << jugadores.size() << "\n";
      for (int i = 0; i < jugadores.size(); i++) {
        o << jugadores[i].usuario << "\n\t";
        o << jugadores[i].nombre << "\n\t";
        o << jugadores[i].apellido << "\n";
      }
      return;
    }
  }

  jugadores.push_back(Jugador {nombre, apellido, usuario});

  sort(jugadores.begin(), jugadores.end(), comparar_por_apellido);

  o << jugadores.size() << "\n";

  for (int i = 0; i < jugadores.size(); i++) {
    o << jugadores[i].usuario << "\n\t";
    o << jugadores[i].nombre << "\n\t";
    o << jugadores[i].apellido << "\n";
  }
}

void mostrar_jugadores() {

  std::vector<Jugador> players_data = obtener_datos_de_jugadores();

  for (int i = 0; i < players_data.size(); i++) {
    std::cout << "Usuario: " << players_data[i].usuario << "\n\t";
    std::cout << "Nombre: " << players_data[i].nombre << "\n\t";
    std::cout << "Apellido: " << players_data[i].apellido << "\n";
  }
}
