#include <string>
#include <vector>

#ifndef GENTABLE
#define GENTABLE

struct Celda {
  std::string jugador_receptor;
  int valor_celda;
  bool atrapada = false;
  bool especial[5];
  // order
  // bool is_prime = false;
  // bool is_palindrome = false;
  // bool is_friend = false;
  // bool is_perfect = false;
  // bool in_diagonal = false;
};

int obtener_numero_aleatorio();

int calcular_suma_de_divisores(int numero);

bool es_numero_amigo(int numero);

bool es_primo(int numero);

bool es_palindromo(int numero);

bool es_numero_perfecto(int numero);

std::vector<std::vector<Celda>> generar_tabla(int &puntaje_dorado);

#endif
