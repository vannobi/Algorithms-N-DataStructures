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

//5-MERGE SORT
void Intercala(int arreglo[], int inicio,int medio, int fin){
	vector<int> auxiliar(fin-inicio+1);
	int i;
	int j;
	int k;
	for(i=inicio;i<=medio;i++){
		auxiliar[i-inicio]=arreglo[i];
	}
	for(j=medio+1;j<=fin;j++){
		auxiliar[fin+medio+1-j-inicio]=arreglo[j];
	}
	i=inicio;
	j=fin;
	for(k=inicio;k<=fin;k++){
		if(auxiliar[i-inicio]<=auxiliar[j-inicio]){
			arreglo[k]=auxiliar[i-inicio];
			i=i+1;
		}else{
			arreglo[k]=auxiliar[j-inicio];
			j=j-1;
		}
	}

}

void MergeSort(int arreglo[], int inicio, int fin){
	if(inicio<fin){
		int medio=floor((inicio+fin)/2);
		MergeSort(arreglo,inicio,medio);
		MergeSort(arreglo,medio+1,fin);
		Intercala(arreglo,inicio,medio,fin);
		
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

		//cout<<"Merge SOrt "<<n*paso-1<<endl;
		//imprimir(arr2,n*paso-1);
		auto inicioSort2 = chrono::high_resolution_clock::now();
	    MergeSort(arr,0,n*paso-1);
		auto finSort2 = chrono::high_resolution_clock::now();
		long long tiemposort2 = chrono::duration_cast<chrono::nanoseconds> (finSort2-inicioSort2).count();
		valoresY[n-1]=tiemposort2/1000;		
		//imprimir(arr2,n*paso-1);
		//cout<<endl;

		delete [] arr;
	}
	
		fe.close();
	 //Lee el archivo puntosGraficar par aguardar los valores
    FILE * archivoPuntos2 = fopen("MergeSort.txt", "w");

    for (int i=0;i<NUM_PUNTOS;i++){
		 fprintf(archivoPuntos2, "%f %f \n", valoresX[i], valoresY[i]); 
 	 }

    fclose(archivoPuntos2);

	 delete [] valoresX;
	 delete [] valoresY;

   return 0;

}
