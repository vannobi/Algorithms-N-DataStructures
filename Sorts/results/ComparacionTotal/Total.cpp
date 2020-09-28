//gcc -Wall orden.cpp -lm -o grafica

#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	 int NUM_COMANDOS=21;

    char * configGnuplot[] = {"set title \"Comparacion: NroDatos VS Tiempo\"", 
                                "set ylabel \"Tiempo Mili-Segundos (10e-6)\"",
                                "set xlabel \"NroDatos\"",
										  "plot \"MergeSortPython.txt\" using 1:2 with lines",
										  "replot \"QuickSortPython.txt\" using 1:2 with lines",
										  "replot \"CountingSortPython.txt\" using 1:2 with lines",
										  "replot \"HeapSortPython.txt\" using 1:2 with lines",

                      "replot \"BubbleSortC++.txt\" using 1:2 with lines",
										  "replot \"InsertionSortC++.txt\" using 1:2 with lines",
										  "replot \"MergeSortC++.txt\" using 1:2 with lines",
										  "replot \"QuickSortC++.txt\" using 1:2 with lines",
										  "replot \"CountingSortC++.txt\" using 1:2 with lines",
										  "replot \"HeapSortC++.txt\" using 1:2 with lines",
										  "replot \"SelectionSortC++.txt\" using 1:2 with lines",

                      "replot \"BubbleSortJava.txt\" using 1:2 with lines",
										  "replot \"InsertionSortJava.txt\" using 1:2 with lines",
										  "replot \"MergeSortJava.txt\" using 1:2 with lines",
										  "replot \"QuickSortJava.txt\" using 1:2 with lines",
										  "replot \"CountingSortJava.txt\" using 1:2 with lines",
										  "replot \"HeapSortJava.txt\" using 1:2 with lines",
										  "replot \"SelectionSortJava.txt\" using 1:2 with lines"

                               };

    FILE * ventanaGnuplot = popen ("gnuplot -persist", "w");

    // Ejecuta los comandos del GNU Plot uno por uno
    for (int i=0;i<NUM_COMANDOS;i++){
		 fprintf(ventanaGnuplot, "%s \n", configGnuplot[i]);
	 }

    return 0;

}
