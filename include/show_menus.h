#include "chose_player.h"
#include "gen_table.h"
#include <string>
#include <vector>

#ifndef SHOWMENUS
#define SHOWMENUS

void mostrar_jugador_ganador(Jugador *winner);

void mostrar_menu_principal(bool table_created, size_t players_size, int &golden_score);

void mostrar_menu_de_juego(std::vector<Jugador> &players);

void mostrar_resultado_de_jugador(Jugador &jugador, std::pair<int, int> dices,
                         Celda &celda, int puntaje);

#endif // SHOWMENUS
