#include "chose_player.h"
#include "gen_table.h"

#ifndef PLAY
#define PLAY
std::pair<int, int> generar_dados();

int obtener_puntaje(Celda &celda);

void tirar_dados(std::vector<Jugador> &jugadores,
                 std::vector<std::vector<Celda>> &tabla, int *puntaje_dorado);

void jugar(std::vector<Jugador> &jugadores, std::vector<std::vector<Celda>> &tabla, int &puntaje_dorado);

#endif
