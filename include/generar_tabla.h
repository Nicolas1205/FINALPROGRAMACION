#include <string>

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

int obtener_numero_aleatorio(bool existe_en_tabla[1000]);

int calcular_suma_de_divisores(int numero);

bool es_numero_amigo(int numero);

bool es_numero_primo(int numero);

bool es_numero_palindromo(int numero);

bool es_numero_perfecto(int numero);

void generar_tabla(int &puntaje_dorado, Celda tabla[10][10]);

#endif
