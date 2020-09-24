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

//6-QUICK SORT
int Particion(int arreglo[], int inicio, int fin)  
{  
	 int pivote=arreglo[fin];
	 int i=inicio-1;

	 int auxiliar;	 

	 for(int j=inicio;j<fin;j++){
			if(arreglo[j]<=pivote){
				i=i+1;
				auxiliar=arreglo[i];
				arreglo[i]=arreglo[j];
				arreglo[j]=auxiliar;
			}
	 }
	 auxiliar=arreglo[i+1];
	 arreglo[i+1]=arreglo[fin];
	 arreglo[fin]=auxiliar;
	return i+1;
	
}  

void QuickSort(int arreglo[], int inicio, int fin) 
{  
	if(inicio<fin){
		int medio=Particion(arreglo,inicio,fin);
		QuickSort(arreglo,inicio,medio-1);
		
		QuickSort(arreglo,medio+1,fin);
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

		//cout<<"Quick SOrt "<<n*paso-1<<endl;
		//imprimir(arr,n*paso-1);
		auto inicioSort = chrono::high_resolution_clock::now();
	    QuickSort(arr,0,n*paso-1);
		auto finSort = chrono::high_resolution_clock::now();
		long long tiemposort = chrono::duration_cast<chrono::nanoseconds> (finSort-inicioSort).count();
		valoresY[n-1]=tiemposort/1000;
		//imprimir(arr,n*paso-1);
		//cout<<endl;

		delete [] arr;
	}
	
		fe.close();
	 //Lee el archivo puntosGraficar par aguardar los valores
    FILE * archivoPuntos = fopen("QuickSort.txt", "w");

    for (int i=0;i<NUM_PUNTOS;i++){
 		 fprintf(archivoPuntos, "%f %f \n", valoresX[i], valoresY[i]);
 	 }

    fclose(archivoPuntos);

	 delete [] valoresX;
	 delete [] valoresY;

   return 0;

}
