#pragma once
#include <iostream>
namespace SS {

int* sort(int* arr, int size) {
  int n = size;
  for (int i = 0; i < n - 1; i++) {
    // Initial index of min
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[min] > arr[j]) {
        min = j;
      }
    }
    // Swapping if index of min is changed
    if (min != i) {
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
  }
  return arr;
}
}  // namespace SS