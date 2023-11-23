#include "../include/criba_erastostenes.h"
#include <math.h>
#include <stdio.h>
#include <vector>

std::vector<bool> crear_criba() {

  std::vector<bool> criba(10000, 1);

  criba[0] = 0;
  criba[1] = 0;

  for (int i = 2; i <= sqrt(criba.size()); i++) {
    for (int j = i << 1; j < criba.size(); j += i) {
      criba[j] = 0;
    }
  }

  return criba;
}
