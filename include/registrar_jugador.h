#include <string>
#ifndef REGISTERPLAYER
#define REGISTERPLAYER

struct Jugador {
  std::string nombre;
  std::string apellido;
  std::string usuario;
  bool jugando = false;
  int puntaje_total = 0;
  int turnos = 1;
  int nada_atrapado = 0;
};

bool comparar_por_apellido(Jugador a, Jugador b);

void crear_jugador(std::string nombre, std::string apellido, std::string usuario,
                 Jugador jugadores[10], int &posicion_ultimo_jugador);

void mostrar_jugadores(Jugador jugadores[10]);

#endif
