#include "../include/generar_tabla.h"
#include "../include/criba_erastostenes.h"
#include <algorithm>
#include <cstdint>
#include <random>
#include <string>
#include <vector>

const int8_t COLUMNAS = 10;
const int8_t FILAS = 10;

std::vector<bool> existe(100, 0);

std::vector<bool> criba = crear_criba();

int contar_primos = 0, contar_capicua = 0, contar_ambos = 0;

/**
* Obtiene un numero aleatorio
*
* Comprueba que el numero no esta en la tabla aun con el arreglo `existe_en_tabla` 
*/
int obtener_numero_aleatorio() {

  std::random_device r;
  std::default_random_engine el(r());
  std::uniform_int_distribution<int> uniform_dist(1, 100);

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
    contar_capicua++;
    return true;
  }
  return false;
}

bool es_numero_primo(int number) { return criba[number]; }

bool es_numero_perfecto(int number) { return calcular_suma_de_divisores(number) == number; }

bool es_numero_amigo(int number) {
  return number == calcular_suma_de_divisores(calcular_suma_de_divisores(number));
}

/**
* Genera la tabla de juego
* 
* Devuelve el arreglo resultante con los valores y puntaje de celda, numeros especiales ya generados
* Modifica el valor del puntaje dorado por referencia
*/
std::vector<std::vector<Celda>> generar_tabla(int &puntaje_dorado) {

  std::vector<std::vector<Celda>> tabla(COLUMNAS, std::vector<Celda>(FILAS));

  for (int i = 0; i < COLUMNAS; i++) {
    for (int j = 0; j < FILAS; j++) {
      int numero_aleatorio = obtener_numero_aleatorio();
      tabla[i][j].numero_celda = numero_aleatorio;
      tabla[i][j].es_primo = es_numero_primo(numero_aleatorio);
      tabla[i][j].es_capicua = es_numero_palindromo(numero_aleatorio);
      tabla[i][j].es_amigo = es_numero_amigo(numero_aleatorio);
      tabla[i][j].es_perfecto = es_numero_perfecto(numero_aleatorio);
      if(i == j) {
        tabla[i][j].es_diagonal = true;
      }
      if(tabla[i][j].es_primo && tabla[i][j].es_capicua) {
        contar_ambos++;
      }
    }
  }

  puntaje_dorado = contar_primos + contar_capicua + contar_ambos + 1000;

  return tabla;
}
