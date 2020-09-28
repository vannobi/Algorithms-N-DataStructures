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

//3-HEAP SORT
void amontonar(int arr[], int n, int i) 
{ 
    int masGrande = i;
    int izquierda = 2*i + 1;
 
    int derecha = 2*i + 2;

    if (izquierda < n && arr[izquierda] > arr[masGrande]) 
        masGrande = izquierda; 

    if (derecha < n && arr[derecha] > arr[masGrande]) 
        masGrande = derecha; 

    if (masGrande != i) 
    { 
        swap(arr[i], arr[masGrande]); 

        amontonar(arr, n, masGrande); 
    } 
} 
  
void heapSort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        amontonar(arr, n, i); 
    for (int i=n-1; i>0; i--) 
    { 
        swap(arr[0], arr[i]); 
        amontonar(arr, i, 0); 
    } 
} 

int main(){
	 ifstream fe("Puntos1.txt");
	 int NUM_ELEMENTOS;
	 int paso;
	 fe >> NUM_ELEMENTOS;
	 fe >> paso;
	 int NUM_PUNTOS=NUM_ELEMENTOS/paso;
	 
    // X, Y valores de los puntos a graficar
	 double * valoresX;
	 valoresX = new double [NUM_PUNTOS];
	 double * valoresY;
	 valoresY = new double [NUM_PUNTOS];

	 register int i=0;
	 
	
	for(int n=1;n<=NUM_PUNTOS;n++){
		cout<<n<<endl;
		int * arr;
	 	arr = new int [n*paso];		

		valoresX[n-1]=n*paso;
		
		for(int i=1;i<=n*paso;i++){
			fe >> arr[i-1];
		}

		//cout<<"Heap SOrt "<<n*paso-1<<endl;
		//imprimir(arr6,n*paso-1);
		auto inicioSort6 = chrono::high_resolution_clock::now();
		heapSort(arr,n*paso-1); 
		auto finSort6 = chrono::high_resolution_clock::now();
		long long tiemposort6 = chrono::duration_cast<chrono::nanoseconds> (finSort6-inicioSort6).count();
		valoresY[n-1]=tiemposort6/1000;
		//imprimir(arr6,n*paso-1);
		//cout<<endl;

		delete [] arr;
	}
	
		fe.close();
	 //Lee el archivo puntosGraficar par aguardar los valores
    FILE * archivoPuntos6 = fopen("HeapSort.txt", "w");

    for (int i=0;i<NUM_PUNTOS;i++){
		 fprintf(archivoPuntos6, "%f %f \n", valoresX[i], valoresY[i]);
 	 }

    fclose(archivoPuntos6);

	 delete [] valoresX;
	 delete [] valoresY;

   return 0;

}
