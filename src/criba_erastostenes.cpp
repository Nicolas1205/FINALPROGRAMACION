#include "../include/criba_erastostenes.h"
#include <math.h>
#include <stdio.h>

/**
* Crea un arreglo con los valores primos ya generados
*
* Devuelve un vector de booleanos, en donde 1 si es primo y 0 si no lo es
*/
void crear_criba(bool criba[1000]) {

  criba[0] = 0;
  criba[1] = 0;

  for (int i = 2; i <= sqrt(1000); i++) {
    for (int j = i << 1; j < 1000; j += i) {
      criba[j] = 0;
    }
  }
}
