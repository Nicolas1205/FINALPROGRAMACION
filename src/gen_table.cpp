#include "../include/gen_table.h"
#include "../include/sieve.h"
#include <algorithm>
#include <cstdint>
#include <random>
#include <string>
#include <vector>

const int8_t COLUMNAS = 10;
const int8_t FILAS = 10;

std::vector<bool> existe(1001, 0);

std::vector<bool> criba = crear_criba();

int count_primes = 0, count_palindromes = 0, count_both = 0;

int obtener_numero_aleatorio() {

  std::random_device r;
  std::default_random_engine el(r());
  std::uniform_int_distribution<int> uniform_dist(1, 1000);

  int random = uniform_dist(el);
  if (!existe[random]) {
    existe[random] = 1;
    return random;
  }
  return obtener_numero_aleatorio();
}

int calcular_suma_de_divisores(int number) {
  int sum = 0;
  for (int i = 1; i < number; i++) {
    if (!(number % i))
      sum += i;
  }
  return sum;
}

bool es_numero_palindromo(int number) {

  std::string palindrome = std::to_string(number), s = palindrome;

  std::reverse(s.begin(), s.end());

  if (s == palindrome) {
    count_palindromes++;
    return true;
  }
  return false;
}

bool es_numero_primo(int number) { return criba[number]; }

bool es_numero_perfecto(int number) { return calcular_suma_de_divisores(number) == number; }

bool es_numero_amigo(int number) {
  return number == calcular_suma_de_divisores(calcular_suma_de_divisores(number));
}

std::vector<std::vector<Celda>> generar_tabla(int &puntaje_dorado) {

  std::vector<std::vector<Celda>> tabla(COLUMNAS, std::vector<Celda>(FILAS));

  bool (*ptr_funciones[])(int) = {es_numero_primo, es_numero_palindromo,
                                  es_numero_amigo, es_numero_perfecto};

  for (int i = 0; i < COLUMNAS; i++) {
    for (int j = 0; j < FILAS; j++) {
      int numero_aleatorio = obtener_numero_aleatorio();
      tabla[i][j].valor_celda = numero_aleatorio;
      for (int k = 0; k < 4; k++) {
        tabla[i][j].especial[k] = (*ptr_funciones[k])(numero_aleatorio);
      }
      tabla[i][j].especial[0] && tabla[i][j].especial[1] ? count_both++ : 0;
      tabla[i][j].especial[4] = i == j ? 1 : 0;
    }
  }

  puntaje_dorado = count_primes + count_palindromes + count_both + 10000;

  return tabla;
}
