#include "../include/generar_tabla.h"
#include "../include/criba_erastostenes.h"
#include <algorithm>
#include <cstdint>
#include <random>
#include <string>

const int COLUMNAS = 10;
const int FILAS = 10;


int contar_primos = 0, contar_capicua = 0, contar_ambos = 0;

/**
* Obtiene un numero aleatorio
*
* Comprueba que el numero no esta en la tabla aun con el arreglo `existe_en_tabla` 
*/
int obtener_numero_aleatorio(bool existe_en_tabla[1000]) {

  int numero_aleatorio = rand() % 1000; 
  if (!existe_en_tabla[numero_aleatorio]) {
    existe_en_tabla[numero_aleatorio] = 1;
    return numero_aleatorio;
  }
  return obtener_numero_aleatorio(existe_en_tabla);
}

int calcular_suma_de_divisores(int number) {
  int sum = 0;
  for (int i = 1; i < number; i++) {
    if (!(number % i))
      sum += i;
  }
  return sum;
}

int numero_reverso(int numero) {
    int numero_reverso = 0;
    while (numero != 0) {
        int digito = numero % 10;
        numero_reverso = numero_reverso * 10 + digito;
        numero /= 10;
    }
    return numero_reverso;
}

bool es_numero_capicua(int numero) {
  if (numero_reverso(numero) == numero) {
    contar_capicua++;
    return true;
  }
  return false;
}

bool es_numero_primo(int number, bool criba[1000]) { return criba[number]; }

bool es_numero_perfecto(int number) { return calcular_suma_de_divisores(number) == number; }

bool es_numero_amigo(int number) {
  return number == calcular_suma_de_divisores(calcular_suma_de_divisores(number));
}

/**
* Genera la tabla de juego
* 
* Devuelve el arreglo resultante con los valores y puntaje de celda, numeros especiales ya generados
* Genera el valor del puntaje dorado por referencia
*/
void generar_tabla(int &puntaje_dorado, Celda tabla[10][10]) {

  bool existe_en_tabla[1000] = { false };
  bool criba[1000] = { true };
  crear_criba(criba);

  for (int i = 0; i < COLUMNAS; i++) {
    for (int j = 0; j < FILAS; j++) {
      int numero_aleatorio = obtener_numero_aleatorio(existe_en_tabla);
      tabla[i][j].numero_celda = numero_aleatorio;
      tabla[i][j].es_primo = es_numero_primo(numero_aleatorio, criba);
      tabla[i][j].es_capicua = es_numero_capicua(numero_aleatorio);
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
}
