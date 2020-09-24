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

//2-COUNTING SORT
void countingSort(int arr[],int n,int rango){
    int c[rango]={0};
    int i;
    int out[n];


    for(i=0;i<n;i++)
    ++c[arr[i]];

    for(i=1;i<rango;i++)
    c[i]+=c[i-1];

    for(i=n-1;i>=0;i--){
        out[c[arr[i]]-1]=arr[i];
        --c[arr[i]];
    }

    for(i=0;i<n;i++)
    arr[i]=out[i];
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

		//cout<<"Counting SOrt "<<n*paso-1<<endl;
		//imprimir(arr5,n*paso-1);
		auto inicioSort5 = chrono::high_resolution_clock::now();
		countingSort(arr,n*paso-1,n*paso);
		auto finSort5 = chrono::high_resolution_clock::now();
		long long tiemposort5 = chrono::duration_cast<chrono::nanoseconds> (finSort5-inicioSort5).count();
		valoresY[n-1]=tiemposort5/1000;
		//imprimir(arr5,n*paso-1);
		//cout<<endl;		


		delete [] arr;
	}
	
		fe.close();
	 //Lee el archivo puntosGraficar par aguardar los valores
    FILE * archivoPuntos5 = fopen("CountingSort.txt", "w");

    for (int i=0;i<NUM_PUNTOS;i++){
		 fprintf(archivoPuntos5, "%f %f \n", valoresX[i], valoresY[i]);
 	 }

    fclose(archivoPuntos5);

	 delete [] valoresX;
	 delete [] valoresY;


   return 0;

}
