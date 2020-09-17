//g++ orden.cpp -std=c++11 -lpthread -o orden.out
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <chrono>
#include <time.h>
#include <bits/stdc++.h>
#include <fstream>
#include <thread>

using namespace std;

#include <quick.h>

#include <merge.h>

#include <insertion.h>

#include <bubble.h>


int main(){

	 int NUM_ELEMENTOS=1000;
	 int paso=100;
	 int NUM_PUNTOS=NUM_ELEMENTOS/paso;

    // X, Y valores de los puntos a graficar
	 double * valoresX;
	 valoresX = new double [NUM_PUNTOS];
	 double * valoresY;
	 valoresY = new double [NUM_PUNTOS];
	 double * valoresY2;
	 valoresY2 = new double [NUM_PUNTOS];
	 double * valoresY3;
	 valoresY3 = new double [NUM_PUNTOS];
	 double * valoresY4;
	 valoresY4 = new double [NUM_PUNTOS];
	
	 register int i=0;

	 srand(time(NULL));
	
	for(int n=1;n<=NUM_PUNTOS;n++){
		int * arr;
	 	arr = new int [n*paso];	
	 	int * arr2;
	 	arr2 = new int [n*paso];	
	 	int * arr3;
	 	arr3 = new int [n*paso];	
	 	int * arr4;
	 	arr4 = new int [n*paso];
		
		valoresX[n-1]=n*paso;
		
		for(int i=1;i<=n*paso;i++){
			arr[i-1]=1 + rand() % (NUM_PUNTOS*NUM_PUNTOS - 1);
			arr2[i-1]=arr[i-1];
			arr3[i-1]=arr[i-1];
			arr4[i-1]=arr[i-1];
		}
		int nn = sizeof(arr) / sizeof(arr[0]);

		auto inicioSort = chrono::high_resolution_clock::now();
	    QuickSort(arr,0,nn);
		auto finSort = chrono::high_resolution_clock::now();
		long long tiemposort = chrono::duration_cast<chrono::nanoseconds> (finSort-inicioSort).count();
		valoresY[n-1]=tiemposort;

		auto inicioSort2 = chrono::high_resolution_clock::now();
	    MergeSort(arr2,0,nn);
		auto finSort2 = chrono::high_resolution_clock::now();
		long long tiemposort2 = chrono::duration_cast<chrono::nanoseconds> (finSort2-inicioSort2).count();
		valoresY2[n-1]=tiemposort2;		

		auto inicioSort3 = chrono::high_resolution_clock::now();
	    InsertionSort(arr3,nn);
		auto finSort3 = chrono::high_resolution_clock::now();
		long long tiemposort3 = chrono::duration_cast<chrono::nanoseconds> (finSort3-inicioSort3).count();
		valoresY3[n-1]=tiemposort3;

		auto inicioSort4 = chrono::high_resolution_clock::now();
	    BubbleSort(arr4,nn);
		auto finSort4 = chrono::high_resolution_clock::now();
		long long tiemposort4 = chrono::duration_cast<chrono::nanoseconds> (finSort4-inicioSort4).count();
		valoresY4[n-1]=tiemposort4;

		delete [] arr;
		delete [] arr2;
		delete [] arr3;
		delete [] arr4;
	}
	

	 //Lee el archivo puntosGraficar par aguardar los valores
    FILE * archivoPuntos = fopen("QuickSort.txt", "w");
    FILE * archivoPuntos2 = fopen("MergeSort.txt", "w");
    FILE * archivoPuntos3 = fopen("InsertionSort.txt", "w");
    FILE * archivoPuntos4 = fopen("BubbleSort.txt", "w");

    for (int i=0;i<NUM_PUNTOS;i++){
 		 fprintf(archivoPuntos, "%f %f \n", valoresX[i], valoresY[i]);
		 fprintf(archivoPuntos2, "%f %f \n", valoresX[i], valoresY2[i]);
		 fprintf(archivoPuntos3, "%f %f \n", valoresX[i], valoresY3[i]);
		 fprintf(archivoPuntos4, "%f %f \n", valoresX[i], valoresY4[i]); 
 	 }

    fclose(archivoPuntos);
    fclose(archivoPuntos2);
    fclose(archivoPuntos3);
    fclose(archivoPuntos4);

	 delete [] valoresX;
	 delete [] valoresY;
	 delete [] valoresY2;
	 delete [] valoresY3;
	 delete [] valoresY4;

   return 0;

}
