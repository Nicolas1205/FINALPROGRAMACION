#include "register_player.h"
#include <string>

#ifndef CHOSEPLAYER

#define CHOSEPLAYER

bool search_player(std::string usuario, std::vector<Jugador> &jugadores,
                   std::vector<Jugador> &players, int p);

std::vector<Jugador> chose_players();

#endif
