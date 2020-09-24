#pragma once
#include <iostream>
namespace IS {
int* sort(int* array, int size) {
  for (int j = 1; j < size; j++) {
    int key = array[j];
    int i = j - 1;
    while (i >= 0 && key < array[i]) {
      array[i + 1] = array[i];
      i--;
    }
    array[i + 1] = key;
  }
  return array;
}
}  // namespace IS