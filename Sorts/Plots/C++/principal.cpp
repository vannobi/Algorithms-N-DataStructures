//gcc -Wall orden.cpp -lm -o grafica

#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	 system("g++ Ordenamiento.cpp -o orden.out");
	 system("./orden.out");
	 system("gcc -Wall grafica.cpp -lm -o grafica");
	 system("./grafica");
    return 0;

}
