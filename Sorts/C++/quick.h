//QUICK SORT
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
