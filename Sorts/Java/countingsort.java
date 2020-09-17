public class Algoritmos {

/*
* Algoritmo2
*/
public int[] countinsort(int[] A) {
int n = A.length-1;
int k = A[0];
for (int i = 1; i <= n; i++) {
if (A[i] > k) {
k = A[i];
}
}
int[] C = new int[k + 1];

for (int i = 0; i <= k; i++) {
C[i] = 0;
}
for (int i = 0; i <= n; i++) {
C[A[i]] = C[A[i]] + 1;
}
for (int i = 1; i <= k; i++) {
C[i] = C[i] + C[i - 1];
}
int[] B = new int[n+1];
for (int i = n ; i >= 0; i--) {
C[A[i]] = C[A[i]] - 1;
B[C[A[i]]] = A[i];
}
return B;
}

public void imprimir (int []a){
String res="";
for (int i = 0; i < a.length; i++) {
res=res+a[i]+", ";
}
System.out.println(res);
}

public static void main(String[] args) {
Algoritmos a = new Algoritmos();
int arre []= {10,9,8,7,150,6,5,4,3,2,1};
a.imprimir(a.countinsort(arre));
}

}