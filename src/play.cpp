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

const char *LIMPIAR_PANTALLA = "\033[2J\033[1;1H";

std::pair<int, int> generar_dados() {
  return std::make_pair(uniform_dist(el), uniform_dist(el));
}

int obtener_puntaje(Celda &celda) {
  int puntaje = 0; 
  if(celda.es_primo && celda.es_capicua && celda.es_diagonal) {
    puntaje = celda.numero_celda * 4;
  }
  else if (celda.es_primo && celda.es_capicua) {
    puntaje = celda.numero_celda * 3;
  }
  else if (celda.es_primo || celda.es_capicua && celda.es_diagonal) {
    puntaje = celda.numero_celda * 2; 
  } else if(celda.es_primo || celda.es_capicua) {
    puntaje = celda.numero_celda; 
  }
  return puntaje;
}

void tirar_dados(std::vector<Jugador> &jugadores_en_juego,
                 std::vector<std::vector<Celda>> &tabla, int &puntaje_dorado) {

  bool turno_jugador = 0;

  while (1) {
    while (jugadores_en_juego[turno_jugador].turnos--) {
      auto [d1, d2] = generar_dados();

      int puntos_obtenidos = 0;

      Celda celda = tabla[d1][d2];

      // modolurizar
      if (tabla[d1][d2].atrapada == false) {
        tabla[d1][d2].atrapada= true;
        tabla[d1][d2].jugador_receptor = jugadores_en_juego[turno_jugador].usuario;
      } else if (tabla[d1][d2].atrapada &&
                 tabla[d1][d2].jugador_receptor !=
                     jugadores_en_juego[turno_jugador].usuario) {

        bool tomada_por = turno_jugador == 1 ? 0 : 1;

        std::cout<<"\nLa Celda: "<<d1<<" "<<d2;
        std::cout << "\nYA HA SIDO TOMADA POR " << jugadores_en_juego[tomada_por].usuario
                  << '\n';
        jugadores_en_juego[turno_jugador].turnos++;
        continue;
      }

      // moduralizar
      if(celda.es_amigo) {
        jugadores_en_juego[turno_jugador].turnos+=1;
      } 
      if(celda.es_perfecto) {
        jugadores_en_juego[turno_jugador].turnos+=2;
      }

      // modularizar
      puntos_obtenidos = obtener_puntaje(celda);
      std::cout<<"puntos: "<<puntos_obtenidos<<'\n';
      jugadores_en_juego[turno_jugador].puntaje_total += puntos_obtenidos;

      if (puntos_obtenidos == 0) {
        jugadores_en_juego[turno_jugador].nada_atrapado++;
      }

      mostrar_resultado_de_jugador(jugadores_en_juego[turno_jugador], std::make_pair(d1, d2),
                          celda, puntos_obtenidos);

      //std::this_thread::sleep_for(std::chrono::seconds(1));

      // moduralizar
      if (jugadores_en_juego[turno_jugador].nada_atrapado >= 3) {
        std::cout << jugadores_en_juego[turno_jugador].usuario
                  << " no ha atrapado numeros especiales"
                     " -10 puntos\n";
        jugadores_en_juego[turno_jugador].puntaje_total -= 10;
        jugadores_en_juego[turno_jugador].nada_atrapado = 0;
      }

      if (jugadores_en_juego[turno_jugador].puntaje_total >= puntaje_dorado) {
        mostrar_jugador_ganador(&jugadores_en_juego[turno_jugador]);
        return;
      }
    }

    // moduralizar
    if(turno_jugador == 0) {
      turno_jugador = 1;
    } else {
      turno_jugador = 0;
    }

    jugadores_en_juego[turno_jugador].turnos = 1;
  }
}

void jugar(std::vector<Jugador> &jugadores, std::vector<std::vector<Celda>> &tabla, int &puntaje_dorado) {

  char opcion_de_juego;
  std::vector<Jugador> jugadores_en_juego;
  bool jugadores_cargados = 0;

  while (1) {
    std::cout << LIMPIAR_PANTALLA;
    mostrar_menu_de_juego(jugadores_en_juego);

    std::cin>>opcion_de_juego;

    if (opcion_de_juego == '1') {
      std::cout << LIMPIAR_PANTALLA;
      jugadores_en_juego = elegir_jugadores(jugadores);
      jugadores_cargados = 1;
    }
    if (opcion_de_juego == '2') {
      std::cout << LIMPIAR_PANTALLA;
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
