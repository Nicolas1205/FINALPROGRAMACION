#include "registrar_jugador.h"
#include <string>

#ifndef CHOSEPLAYER

#define CHOSEPLAYER

bool buscar_jugador(std::string usuario, std::vector<Jugador> &jugadores,
                   std::vector<Jugador> &players, int p);

std::vector<Jugador> elegir_jugadores(std::vector<Jugador> &jugadores);

#endif
