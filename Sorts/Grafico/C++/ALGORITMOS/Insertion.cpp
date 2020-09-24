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


//4-INSERTION SORT
void InsertionSort(int arreglo[],int longitud){
	for(int j=1;j<longitud;j++){
		int clave=arreglo[j];
		int i=j-1;
		while(i>=0 && arreglo[i]>clave){
			arreglo[i+1]=arreglo[i];
			i=i-1;
		}
		arreglo[i+1]=clave;
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

		//cout<<"Insertion SOrt "<<n*paso-1<<endl;
		//imprimir(arr3,n*paso-1);
		auto inicioSort3 = chrono::high_resolution_clock::now();
	    InsertionSort(arr,n*paso-1);
		auto finSort3 = chrono::high_resolution_clock::now();
		long long tiemposort3 = chrono::duration_cast<chrono::nanoseconds> (finSort3-inicioSort3).count();
		valoresY[n-1]=tiemposort3/1000;
		//imprimir(arr3,n*paso-1);
		//cout<<endl;

		delete [] arr;
	}
	
		fe.close();
	 //Lee el archivo puntosGraficar par aguardar los valores
    FILE * archivoPuntos3 = fopen("InsertionSort.txt", "w");

    for (int i=0;i<NUM_PUNTOS;i++){
		 fprintf(archivoPuntos3, "%f %f \n", valoresX[i], valoresY[i]);
 	 }

    fclose(archivoPuntos3);

	 delete [] valoresX;
	 delete [] valoresY;

   return 0;

}
