#include <iostream>
using namespace std;

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
void print(int arr[],int n){
    cout<<"arreglo : ";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<' ';
    cout<<endl;
}

int main() {
	// your code goes here
	int arr[]={1, 4, 1, 2, 7, 5, 2}; // 2,2,0,1,1,0,1,0,0
	int n=sizeof(arr)/sizeof(arr[0]);
	int rango=9;
	print(arr,n);
	countingSort(arr,n,rango);
    print(arr,n);
	return 0;
}
