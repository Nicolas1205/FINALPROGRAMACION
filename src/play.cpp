#include "../include/play.h"
#include "../include/chose_player.h"
#include "../include/gen_table.h"
#include "../include/register_player.h"
#include "../include/show_menus.h"
#include "../include/sieve.h"
#include <chrono>
#include <iostream>
#include <random>
#include <stdio.h>
#include <string>
#include <thread>
#include <utility>
#include <vector>

std::random_device r;
std::default_random_engine el(r());
std::uniform_int_distribution<int> uniform_dist(0, 9);

const char *CLEAR = "\033[2J\033[1;1H";

std::pair<int, int> generar_dados() {
  return std::make_pair(uniform_dist(el), uniform_dist(el));
}

int obtener_puntaje(std::vector<std::vector<Celda>> &table, int d1, int d2) {

  int score = 0, value = table[d1][d2].valor_celda;

  if (table[d1][d2].especial[0] && table[d1][d2].especial[1] &&
      table[d1][d2].especial[4]) {
    score = value * 4;
  } else if (table[d1][d2].especial[0] && table[d1][d2].especial[1]) {
    score = value * 3;
  } else if (table[d1][d2].especial[0] ||
             table[d1][d2].especial[1] && table[d1][d2].especial[4]) {
    score = value * 2;
  } else if (table[d1][d2].especial[0] || table[d1][d2].especial[1]) {
    score = value;
  }

  return score;
}

void tirar_dados(std::vector<Jugador> &jugadores,
                 std::vector<std::vector<Celda>> &tabla, int &puntaje_dorado) {

  bool player_turn = 0;
  while (1) {
    while (jugadores[player_turn].turnos) {
      auto [d1, d2] = generar_dados();

      int puntos_obtenidos = 0;

      if (!tabla[d1][d2].atrapada) {
        tabla[d1][d2].atrapada= true;
        tabla[d1][d2].jugador_receptor = jugadores[player_turn].usuario;
      } else if (tabla[d1][d2].atrapada &&
                 tabla[d1][d2].jugador_receptor !=
                     jugadores[player_turn].usuario) {

        mostrar_resultado_de_jugador(jugadores[player_turn], std::make_pair(d1, d2),
                                     tabla[d1][d2].especial, tabla[d1][d2].valor_celda,
                                     puntos_obtenidos);

        bool property_of = player_turn == 1 ? 0 : 1;
        std::cout << "\nYA HA SIDO TOMADA POR " << jugadores[property_of].usuario
                  << '\n';
        jugadores[player_turn].turnos++;
        continue;
      }

      jugadores[player_turn].turnos+= tabla[d1][d2].especial[2] ? 1 : 0;
      jugadores[player_turn].turnos+= tabla[d1][d2].especial[3] ? 2 : 0;

      puntos_obtenidos = obtener_puntaje(tabla, d1, d2);
      jugadores[player_turn].puntaje_total += puntos_obtenidos;

      if (!puntos_obtenidos)
        jugadores[player_turn].nada_atrapado++;

      mostrar_resultado_de_jugador(jugadores[player_turn], std::make_pair(d1, d2),
                          tabla[d1][d2].especial, tabla[d1][d2].valor_celda,
                          puntos_obtenidos);

      std::this_thread::sleep_for(std::chrono::seconds(1));

      if (jugadores[player_turn].nada_atrapado>= 3) {
        std::cout << jugadores[player_turn].usuario
                  << " no ha atrapado numeros especiales"
                     " -10 puntos\n";
        jugadores[player_turn].puntaje_total -= 10;
        jugadores[player_turn].nada_atrapado = 0;
      }

      if (jugadores[player_turn].puntaje_total >= puntaje_dorado) {
        mostrar_jugador_ganador(&jugadores[player_turn]);
        return;
      }
    }

    player_turn = player_turn == 0 ? 1 : 0;
    jugadores[player_turn].turnos = 1;
  }
}

void jugar(std::vector<std::vector<Celda>> &tabla, int &puntaje_dorado) {

  char opcion_de_juego;
  std::vector<Jugador> jugadores_en_juego;
  bool jugadores_cargados = 0;

  while (1) {
    std::cout << CLEAR;
    mostrar_menu_de_juego(jugadores_en_juego);

    scanf("%c", &opcion_de_juego);

    if (opcion_de_juego == '1') {
      std::cout << CLEAR;
      jugadores_en_juego = chose_players();
      jugadores_cargados = 1;
    }
    if (opcion_de_juego == '2') {
      std::cout << CLEAR;
      if (jugadores_cargados) {
        tirar_dados(jugadores_en_juego, tabla, puntaje_dorado);
        jugadores_en_juego[0].puntaje_total = 0;
        jugadores_en_juego[1].puntaje_total = 0;
        //std::this_thread::sleep_for(std::chrono::seconds(5));
      }
    }
    if (opcion_de_juego == '3')
      return;
  }
}
