#include "elegir_jugador.h"
#include "generar_tabla.h"

#ifndef PLAY
#define PLAY

struct Dados {
  int primero; 
  int segundo;
};

Dados generar_dados();

int obtener_puntaje(Celda &celda);

void tirar_dados(Jugador jugadores_en_juego[2],
                 Celda tabla[10][10], int puntaje_dorado);

void jugar(Jugador jugadores[10], Celda tabla[10][10], int puntaje_dorado);

#endif
