#pragma once
#include <iostream>

namespace BS {

void sort(int arreglo[], int longitud) {
  int auxiliar;
  for (int i = 0; i < longitud - 1; i++) {
    // Last i elements are already in place
    for (int j = 0; j < longitud - i - 1; j++) {
      if (arreglo[j] > arreglo[j + 1]) {
        auxiliar = arreglo[j];
        arreglo[j] = arreglo[j + 1];
        arreglo[j + 1] = auxiliar;
      }
    }
  }
}
}  // namespace BS