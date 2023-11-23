#include "elegir_jugador.h"
#include "generar_tabla.h"
#include <string>
#include <vector>

#ifndef SHOWMENUS
#define SHOWMENUS

void mostrar_jugador_ganador(Jugador &jugador_ganador);

void mostrar_menu_principal(bool tabla_creada, size_t cantidad_jugadores, int puntaje_dorado);

void mostrar_menu_de_juego(std::vector<Jugador> &jugadores);

void mostrar_resultado_de_jugador(Jugador &jugador, std::pair<int, int> dices,
                         Celda &celda, int puntaje);

#endif
