#include <string>
#include <vector>

#ifndef GENTABLE
#define GENTABLE

struct Celda {
  int numero_celda;
  int puntaje_celda;

  bool atrapada = false;

  bool es_primo = false;
  bool es_capicua = false;
  bool es_amigo = false;
  bool es_perfecto = false;
  bool es_diagonal = false;
  std::string jugador_receptor;
};

int obtener_numero_aleatorio();

int calcular_suma_de_divisores(int numero);

bool es_numero_amigo(int numero);

bool es_numero_primo(int numero);

bool es_numero_palindromo(int numero);

bool es_numero_perfecto(int numero);

std::vector<std::vector<Celda>> generar_tabla(int &puntaje_dorado);

#endif
