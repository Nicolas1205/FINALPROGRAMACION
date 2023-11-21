#include "chose_player.h"
#include <string>
#include <vector>

#ifndef SHOWMENUS
#define SHOWMENUS

void mostrar_jugador_ganador(Jugador *winner);

void mostrar_menu_principal(bool table_created, size_t players_size, int &golden_score);

void mostrar_menu_de_juego(std::vector<Jugador> &players);

void mostrar_resultado_de_jugador(Jugador &player, std::pair<int, int> dices,
                         bool specials[], int numero_encontrado, int score);

#endif // SHOWMENUS
