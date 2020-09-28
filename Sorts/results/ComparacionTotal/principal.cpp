//gcc -Wall orden.cpp -lm -o grafica
//g++ principal.cpp -o principal.out

#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	 system("gcc -Wall Total.cpp -lm -o Total");
	 system("./Total");
	 system("gcc -Wall Merge.cpp -lm -o Merge");
	 system("./Merge");
	 system("gcc -Wall Quick.cpp -lm -o Quick");
	 system("./Quick");
	 system("gcc -Wall Counting.cpp -lm -o Counting");
	 system("./Counting");
	 system("gcc -Wall Heap.cpp -lm -o Heap");
	 system("./Heap");
	 system("gcc -Wall Bubble.cpp -lm -o Bubble");
	 system("./Bubble");
	 system("gcc -Wall Insertion.cpp -lm -o Insertion");
	 system("./Insertion");
	 system("gcc -Wall Selection.cpp -lm -o Selection");
	 system("./Selection");
    return 0;

}
