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

//1-BUBBLE SORT
void BubbleSort(int arreglo[],int longitud)  
{  
	 int auxiliar;
    for (int i = 0; i < longitud-1; i++){            
	    // Last i elements are already in place  
	    for (int j = 0; j < longitud-i-1; j++){  
	        if (arreglo[j] > arreglo[j+1]){
					 auxiliar=arreglo[j];
					 arreglo[j]=arreglo[j+1];
					 arreglo[j+1]=auxiliar;
				}
		 }
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
		cout<<n*paso-1<<endl;
		int * arr;
	 	arr = new int [n*paso];	

		valoresX[n-1]=n*paso;
		
		for(int i=1;i<=n*paso;i++){
			fe >> arr[i-1];
		}

		//cout<<"Bubble SOrt "<<n*paso-1<<endl;
		//imprimir(arr4,n*paso-1);
		auto inicioSort4 = chrono::high_resolution_clock::now();
	    BubbleSort(arr,n*paso-1);
		auto finSort4 = chrono::high_resolution_clock::now();
		long long tiemposort4 = chrono::duration_cast<chrono::nanoseconds> (finSort4-inicioSort4).count();
		valoresY[n-1]=tiemposort4/1000;
		//imprimir(arr4,n*paso-1);
		//cout<<endl;

		delete [] arr;

	}
	
		fe.close();
	 //Lee el archivo puntosGraficar par aguardar los valores
    FILE * archivoPuntos4 = fopen("BubbleSort.txt", "w");

    for (int i=0;i<NUM_PUNTOS;i++){
		 fprintf(archivoPuntos4, "%f %f \n", valoresX[i], valoresY[i]);
 	 }

    fclose(archivoPuntos4);

	 delete [] valoresX;
	 delete [] valoresY;

   return 0;

}
