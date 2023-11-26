#include "elegir_jugador.h"
#include "generar_tabla.h"
#include "jugar.h"
#include <string>

#ifndef SHOWMENUS
#define SHOWMENUS

void mostrar_jugador_ganador(Jugador &jugador_ganador);

void mostrar_menu_principal(bool tabla_creada, size_t cantidad_jugadores, int puntaje_dorado);

void mostrar_menu_de_juego(Jugador jugadores[10], bool jugadores_cargados);

void mostrar_resultado_de_jugador(Jugador &jugador, Dados dados,
                         Celda &celda, int puntos_obtenidos);

#endif
