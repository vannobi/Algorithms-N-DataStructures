#pragma once
#include <iostream>

namespace CS {

void countingSort(int* ar, int size, int minVal, int maxVal);
void sort(int* values, int size);

void sort(int* values, int size) {
  int minValue = values[0];
  int maxValue = values[0];
  for (int i = 0; i < size; i++) {
    if (values[i] < minValue) minValue = values[i];
    if (values[i] > maxValue) maxValue = values[i];
  }
  int sz = maxValue - minValue + 1;
  int* countingArr = new int[sz]();
  for (int i = 0; i < size; i++) countingArr[values[i] - minValue]++;
  for (int i = 0, k = 0; i < sz; i++) {
    while (countingArr[i]-- > 0) {
      values[k++] = i + minValue;
    }
  }
  delete[] countingArr;
}

}  // namespace CS