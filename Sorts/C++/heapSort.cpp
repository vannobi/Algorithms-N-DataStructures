#include <iostream> 
  
using namespace std; 

void amontonar(int arr[], int n, int i) 
{ 
    int masGrande = i;
    int izquierda = 2*i + 1;
 
    int derecha = 2*i + 2;

    if (izquierda < n && arr[izquierda] > arr[masGrande]) 
        masGrande = izquierda; 

    if (derecha < n && arr[derecha] > arr[masGrande]) 
        masGrande = derecha; 

    if (masGrande != i) 
    { 
        swap(arr[i], arr[masGrande]); 

        amontonar(arr, n, masGrande); 
    } 
} 
  
  
void heapSort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        amontonar(arr, n, i); 
    for (int i=n-1; i>0; i--) 
    { 
        swap(arr[0], arr[i]); 
        amontonar(arr, i, 0); 
    } 
} 

void imprimir(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout <<endl; 
} 
 
int main() 
{ 
    int arr[]={6,4,5,7,2};
    int n = sizeof(arr)/sizeof(arr[0]);
  
    heapSort(arr, n); 
  
    cout << "Lista ordenada"<<endl; 
    imprimir(arr, n); 
} 