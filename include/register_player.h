#include <string>
#include <vector>
#ifndef REGISTERPLAYER
#define REGISTERPLAYER

struct Jugador {
  std::string nombre;
  std::string apellido;
  std::string usuario;
  bool jugando = false; // ??
  int puntaje_total = 0;
  int turnos = 1;
  int nada_atrapado = 0;
};

std::vector<Jugador> obtener_datos_de_jugadores();

bool comparar_por_apellido(Jugador a, Jugador b);

void crear_jugador(std::string nombre, std::string apellido, std::string usuario,
                 std::vector<Jugador> &jugadores);

void mostrar_jugadores();

#endif
