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

//7-SELECTION SORT
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  

    for (i = 0; i < n-1; i++)  
    {  

        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
 
        swap(&arr[min_idx], &arr[i]);  
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
	 
	for(int n=1;n<=NUM_PUNTOS;n++){
		cout<<n<<endl;
		int * arr;
	 	arr = new int [n*paso];	

		valoresX[n-1]=n*paso;
		
		for(int i=1;i<=n*paso;i++){
			fe >> arr[i-1];
		}

		//cout<<"Selection SOrt "<<n*paso-1<<endl;
		//imprimir(arr7,n*paso-1);
		auto inicioSort7 = chrono::high_resolution_clock::now();
		selectionSort(arr,n*paso-1); 
		auto finSort7 = chrono::high_resolution_clock::now();
		long long tiemposort7 = chrono::duration_cast<chrono::nanoseconds> (finSort7-inicioSort7).count();
		valoresY[n-1]=tiemposort7/1000;
		//imprimir(arr7,n*paso-1);
		//cout<<endl;

		delete [] arr;
	}
	
		fe.close();
	 //Lee el archivo puntosGraficar par aguardar los valores
    FILE * archivoPuntos7 = fopen("SelectionSort.txt", "w");

    for (int i=0;i<NUM_PUNTOS;i++){
		 fprintf(archivoPuntos7, "%f %f \n", valoresX[i], valoresY[i]); 
 	 }

    fclose(archivoPuntos7);

	 delete [] valoresX;
	 delete [] valoresY;

   return 0;

}
