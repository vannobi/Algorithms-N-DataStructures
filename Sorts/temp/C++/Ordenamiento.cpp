// g++ orden.cpp -std=c++11 -lpthread -o orden.out
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

using namespace std;

void imprimir(int arreglo[], int longitud) {
  for (int i = 0; i < longitud; i++) {
    cout << arreglo[i] << " ";
  }
  cout << endl;
}

void imprimirf(float arreglo[], int longitud) {
  for (int i = 0; i < longitud; i++) {
    cout << arreglo[i] << " ";
  }
  cout << endl;
}

// 1-BUBBLE SORT
void BubbleSort(int arreglo[], int longitud) {
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

// 2-COUNTING SORT
void countingSort(int arr[], int n, int rango) {
  int c[rango] = {0};
  int i;
  int out[n];

  for (i = 0; i < n; i++) ++c[arr[i]];

  for (i = 1; i < rango; i++) c[i] += c[i - 1];

  for (i = n - 1; i >= 0; i--) {
    out[c[arr[i]] - 1] = arr[i];
    --c[arr[i]];
  }

  for (i = 0; i < n; i++) arr[i] = out[i];
}

// 3-HEAP SORT
void amontonar(int arr[], int n, int i) {
  int masGrande = i;
  int izquierda = 2 * i + 1;

  int derecha = 2 * i + 2;

  if (izquierda < n && arr[izquierda] > arr[masGrande]) masGrande = izquierda;

  if (derecha < n && arr[derecha] > arr[masGrande]) masGrande = derecha;

  if (masGrande != i) {
    swap(arr[i], arr[masGrande]);

    amontonar(arr, n, masGrande);
  }
}

void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) amontonar(arr, n, i);
  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    amontonar(arr, i, 0);
  }
}

// 4-INSERTION SORT
void InsertionSort(int arreglo[], int longitud) {
  for (int j = 1; j < longitud; j++) {
    int clave = arreglo[j];
    int i = j - 1;
    while (i >= 0 && arreglo[i] > clave) {
      arreglo[i + 1] = arreglo[i];
      i = i - 1;
    }
    arreglo[i + 1] = clave;
  }
}

// 5-MERGE SORT
void Intercala(int arreglo[], int inicio, int medio, int fin) {
  vector<int> auxiliar(fin - inicio + 1);
  int i;
  int j;
  int k;
  for (i = inicio; i <= medio; i++) {
    auxiliar[i - inicio] = arreglo[i];
  }
  for (j = medio + 1; j <= fin; j++) {
    auxiliar[fin + medio + 1 - j - inicio] = arreglo[j];
  }
  i = inicio;
  j = fin;
  for (k = inicio; k <= fin; k++) {
    if (auxiliar[i - inicio] <= auxiliar[j - inicio]) {
      arreglo[k] = auxiliar[i - inicio];
      i = i + 1;
    } else {
      arreglo[k] = auxiliar[j - inicio];
      j = j - 1;
    }
  }
}

void MergeSort(int arreglo[], int inicio, int fin) {
  if (inicio < fin) {
    int medio = floor((inicio + fin) / 2);
    MergeSort(arreglo, inicio, medio);
    MergeSort(arreglo, medio + 1, fin);
    Intercala(arreglo, inicio, medio, fin);
  }
}

// 6-QUICK SORT
int Particion(int arreglo[], int inicio, int fin) {
  int pivote = arreglo[fin];
  int i = inicio - 1;

  int auxiliar;

  for (int j = inicio; j < fin; j++) {
    if (arreglo[j] <= pivote) {
      i = i + 1;
      auxiliar = arreglo[i];
      arreglo[i] = arreglo[j];
      arreglo[j] = auxiliar;
    }
  }
  auxiliar = arreglo[i + 1];
  arreglo[i + 1] = arreglo[fin];
  arreglo[fin] = auxiliar;
  return i + 1;
}

void QuickSort(int arreglo[], int inicio, int fin) {
  if (inicio < fin) {
    int medio = Particion(arreglo, inicio, fin);
    QuickSort(arreglo, inicio, medio - 1);

    QuickSort(arreglo, medio + 1, fin);
  }
}

// 7-SELECTION SORT
void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selectionSort(int arr[], int n) {
  int i, j, min_idx;

  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx]) min_idx = j;

    swap(&arr[min_idx], &arr[i]);
  }
}

int main() {
  int NUM_ELEMENTOS = 100000;
  int paso = 100;
  int NUM_PUNTOS = NUM_ELEMENTOS / paso;

  // X, Y valores de los puntos a graficar
  double *valoresX;
  valoresX = new double[NUM_PUNTOS];
  double *valoresY;
  valoresY = new double[NUM_PUNTOS];
  double *valoresY2;
  valoresY2 = new double[NUM_PUNTOS];
  double *valoresY3;
  valoresY3 = new double[NUM_PUNTOS];
  double *valoresY4;
  valoresY4 = new double[NUM_PUNTOS];
  double *valoresY5;
  valoresY5 = new double[NUM_PUNTOS];
  double *valoresY6;
  valoresY6 = new double[NUM_PUNTOS];
  double *valoresY7;
  valoresY7 = new double[NUM_PUNTOS];
  register int i = 0;

  srand(time(NULL));

  for (int n = 1; n <= NUM_PUNTOS; n++) {
    int *arr;
    arr = new int[n * paso];
    int *arr2;
    arr2 = new int[n * paso];
    int *arr3;
    arr3 = new int[n * paso];
    int *arr4;
    arr4 = new int[n * paso];
    int *arr5;
    arr5 = new int[n * paso];
    int *arr6;
    arr6 = new int[n * paso];
    int *arr7;
    arr7 = new int[n * paso];

    valoresX[n - 1] = n * paso;

    for (int i = 1; i <= n * paso; i++) {
      arr[i - 1] = 1 + rand() % (n * n * paso - 1);
      arr2[i - 1] = arr[i - 1];
      arr3[i - 1] = arr[i - 1];
      arr4[i - 1] = arr[i - 1];
      arr5[i - 1] = arr[i - 1];
      arr6[i - 1] = arr[i - 1];
      arr7[i - 1] = arr[i - 1];
    }

    // cout<<"Quick SOrt "<<n*paso-1<<endl;
    // imprimir(arr,n*paso-1);
    auto inicioSort = chrono::high_resolution_clock::now();
    QuickSort(arr, 0, n * paso - 1);
    auto finSort = chrono::high_resolution_clock::now();
    long long tiemposort =
        chrono::duration_cast<chrono::nanoseconds>(finSort - inicioSort)
            .count();
    valoresY[n - 1] = tiemposort;
    // imprimir(arr,n*paso-1);
    // cout<<endl;

    // cout<<"Merge SOrt "<<n*paso-1<<endl;
    // imprimir(arr2,n*paso-1);
    auto inicioSort2 = chrono::high_resolution_clock::now();
    MergeSort(arr2, 0, n * paso - 1);
    auto finSort2 = chrono::high_resolution_clock::now();
    long long tiemposort2 =
        chrono::duration_cast<chrono::nanoseconds>(finSort2 - inicioSort2)
            .count();
    valoresY2[n - 1] = tiemposort2;
    // imprimir(arr2,n*paso-1);
    // cout<<endl;

    // cout<<"Insertion SOrt "<<n*paso-1<<endl;
    // imprimir(arr3,n*paso-1);
    auto inicioSort3 = chrono::high_resolution_clock::now();
    InsertionSort(arr3, n * paso - 1);
    auto finSort3 = chrono::high_resolution_clock::now();
    long long tiemposort3 =
        chrono::duration_cast<chrono::nanoseconds>(finSort3 - inicioSort3)
            .count();
    valoresY3[n - 1] = tiemposort3;
    // imprimir(arr3,n*paso-1);
    // cout<<endl;

    // cout<<"Bubble SOrt "<<n*paso-1<<endl;
    // imprimir(arr4,n*paso-1);
    auto inicioSort4 = chrono::high_resolution_clock::now();
    BubbleSort(arr4, n * paso - 1);
    auto finSort4 = chrono::high_resolution_clock::now();
    long long tiemposort4 =
        chrono::duration_cast<chrono::nanoseconds>(finSort4 - inicioSort4)
            .count();
    valoresY4[n - 1] = tiemposort4;
    // imprimir(arr4,n*paso-1);
    // cout<<endl;

    // cout<<"Counting SOrt "<<n*paso-1<<endl;
    // imprimir(arr5,n*paso-1);
    auto inicioSort5 = chrono::high_resolution_clock::now();
    countingSort(arr5, n * paso - 1, n * n * paso);
    auto finSort5 = chrono::high_resolution_clock::now();
    long long tiemposort5 =
        chrono::duration_cast<chrono::nanoseconds>(finSort5 - inicioSort5)
            .count();
    valoresY5[n - 1] = tiemposort5;
    // imprimir(arr5,n*paso-1);
    // cout<<endl;

    // cout<<"Heap SOrt "<<n*paso-1<<endl;
    // imprimir(arr6,n*paso-1);
    auto inicioSort6 = chrono::high_resolution_clock::now();
    heapSort(arr6, n * paso - 1);
    auto finSort6 = chrono::high_resolution_clock::now();
    long long tiemposort6 =
        chrono::duration_cast<chrono::nanoseconds>(finSort6 - inicioSort6)
            .count();
    valoresY6[n - 1] = tiemposort6;
    // imprimir(arr6,n*paso-1);
    // cout<<endl;

    // cout<<"Selection SOrt "<<n*paso-1<<endl;
    // imprimir(arr7,n*paso-1);
    auto inicioSort7 = chrono::high_resolution_clock::now();
    selectionSort(arr7, n * paso - 1);
    auto finSort7 = chrono::high_resolution_clock::now();
    long long tiemposort7 =
        chrono::duration_cast<chrono::nanoseconds>(finSort7 - inicioSort7)
            .count();
    valoresY7[n - 1] = tiemposort7;
    // imprimir(arr7,n*paso-1);
    // cout<<endl;

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
  }

  // Lee el archivo puntosGraficar par aguardar los valores
  FILE *archivoPuntos = fopen("QuickSort.txt", "w");
  FILE *archivoPuntos2 = fopen("MergeSort.txt", "w");
  FILE *archivoPuntos3 = fopen("InsertionSort.txt", "w");
  FILE *archivoPuntos4 = fopen("BubbleSort.txt", "w");
  FILE *archivoPuntos5 = fopen("CountingSort.txt", "w");
  FILE *archivoPuntos6 = fopen("HeapSort.txt", "w");
  FILE *archivoPuntos7 = fopen("SelectionSort.txt", "w");

  for (int i = 0; i < NUM_PUNTOS; i++) {
    fprintf(archivoPuntos, "%f %f \n", valoresX[i], valoresY[i]);
    fprintf(archivoPuntos2, "%f %f \n", valoresX[i], valoresY2[i]);
    fprintf(archivoPuntos3, "%f %f \n", valoresX[i], valoresY3[i]);
    fprintf(archivoPuntos4, "%f %f \n", valoresX[i], valoresY4[i]);
    fprintf(archivoPuntos5, "%f %f \n", valoresX[i], valoresY5[i]);
    fprintf(archivoPuntos6, "%f %f \n", valoresX[i], valoresY6[i]);
    fprintf(archivoPuntos7, "%f %f \n", valoresX[i], valoresY7[i]);
  }

  fclose(archivoPuntos);
  fclose(archivoPuntos2);
  fclose(archivoPuntos3);
  fclose(archivoPuntos4);
  fclose(archivoPuntos5);
  fclose(archivoPuntos6);
  fclose(archivoPuntos7);

  delete[] valoresX;
  delete[] valoresY;
  delete[] valoresY2;
  delete[] valoresY3;
  delete[] valoresY4;
  delete[] valoresY5;
  delete[] valoresY6;
  delete[] valoresY7;

  return 0;
}
