#include "registrar_jugador.h"
#include <string>

#ifndef CHOSEPLAYER

#define CHOSEPLAYER

bool buscar_jugador(std::string usuario, Jugador jugadores[10],
                   Jugador jugadores_en_juego[2], int p);

void elegir_jugadores(Jugador jugadores[10], Jugador jugadores_en_juego[2]);

#endif
