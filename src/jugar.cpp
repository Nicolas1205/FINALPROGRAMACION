#include "../include/jugar.h"
#include "../include/elegir_jugador.h"
#include "../include/generar_tabla.h"
#include "../include/registrar_jugador.h"
#include "../include/mostrar_menus.h"
#include "../include/criba_erastostenes.h"
#include <chrono>
#include <iostream>
#include <random>
#include <stdio.h>
#include <string>
#include <thread>
#include <utility>

const char *LIMPIAR_PANTALLA = "\033[2J\033[1;1H";

Dados generar_dados() {
  Dados dados = { rand() % 10, rand() % 10};
  return dados;
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

void tirar_dados(Jugador jugadores_en_juego[2],
                 Celda tabla[10][10], int puntaje_dorado) {

  bool turno_jugador = 0;

  while (1) {
    while (jugadores_en_juego[turno_jugador].turnos--) {
      Dados dados = generar_dados();

      int puntos_obtenidos = 0;

      Celda &celda = tabla[dados.primero][dados.segundo];

      // TODO: modolurizar
      if (celda.atrapada == false) {
        celda.atrapada= true;
        celda.jugador_receptor = jugadores_en_juego[turno_jugador].usuario;
      } else if (celda.atrapada &&
                 celda.jugador_receptor !=
                     jugadores_en_juego[turno_jugador].usuario) {

        bool tomada_por = turno_jugador == 1 ? 0 : 1;

        std::cout<<"\nLa Celda: "<<dados.primero<<" "<<dados.segundo;
        std::cout << "\nYA HA SIDO TOMADA POR " << jugadores_en_juego[tomada_por].usuario
                  << '\n';
        jugadores_en_juego[turno_jugador].turnos++;
        continue;
      }

      // TODO: moduralizar
      if(celda.es_amigo) {
        jugadores_en_juego[turno_jugador].turnos+=1;
      } 
      if(celda.es_perfecto) {
        jugadores_en_juego[turno_jugador].turnos+=2;
      }

      // TODO: modularizar
      puntos_obtenidos = obtener_puntaje(celda);
      std::cout<<"puntos: "<<puntos_obtenidos<<'\n';
      jugadores_en_juego[turno_jugador].puntaje_total += puntos_obtenidos;

      if (puntos_obtenidos == 0) {
        jugadores_en_juego[turno_jugador].nada_atrapado++;
      }

      mostrar_resultado_de_jugador(jugadores_en_juego[turno_jugador], dados,
                          celda, puntos_obtenidos);


      // TODO: moduralizar
      if (jugadores_en_juego[turno_jugador].nada_atrapado >= 3) {
        std::cout << jugadores_en_juego[turno_jugador].usuario
                  << " no ha atrapado numeros especiales"
                     " -10 puntos\n";
        jugadores_en_juego[turno_jugador].puntaje_total -= 10;
        jugadores_en_juego[turno_jugador].nada_atrapado = 0;
      }

      if (jugadores_en_juego[turno_jugador].puntaje_total >= puntaje_dorado) {
        mostrar_jugador_ganador(jugadores_en_juego[turno_jugador]);
        return;
      }
    }

    // TODO: moduralizar
    if(turno_jugador == 0) {
      turno_jugador = 1;
    } else {
      turno_jugador = 0;
    }

    jugadores_en_juego[turno_jugador].turnos = 1;
  }
}

void jugar(Jugador jugadores[10], Celda tabla[10][10], int puntaje_dorado) {

  char opcion_de_juego;
  //std::vector<Jugador> jugadores_en_juego;
  Jugador jugadores_en_juego[2];
  bool jugadores_cargados = false;

  while (1) {
    std::cout << LIMPIAR_PANTALLA;
    mostrar_menu_de_juego(jugadores_en_juego, jugadores_cargados);

    std::cin>>opcion_de_juego;

    if (opcion_de_juego == '1') {
      std::cout << LIMPIAR_PANTALLA;
      elegir_jugadores(jugadores, jugadores_en_juego);
      jugadores_cargados = 1;
    }
    if (opcion_de_juego == '2') {
      std::cout << LIMPIAR_PANTALLA;
      if (jugadores_cargados) {
        tirar_dados(jugadores_en_juego, tabla, puntaje_dorado);

        jugadores_en_juego[0].puntaje_total = 0;
        jugadores_en_juego[1].puntaje_total = 0;
        std::this_thread::sleep_for(std::chrono::seconds(5));
      }
    }
    if (opcion_de_juego == '3')
      return;
  }
}
