//INSERTION SORT
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
