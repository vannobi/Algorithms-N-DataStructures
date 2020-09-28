//javac Ordenar.java
//java Ordenar

import java.util.Random;
import java.io.*;

public class Bubble{

		//Selection Sort
    public static void SelectionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            // Initial index of min
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[min] > arr[j]) {
                    min = j;
                }
            }
            // Swapping if index of min is changed
            if (min != i) {
                swap(arr, i, min);
            }
        }
        
    }

		//Quick Sort
    public static int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }

    public static void QuickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            QuickSort(arr, low, pi - 1);
            QuickSort(arr, pi + 1, high);
        }
    }		

		//Merge Sort
    public static void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[] = new int[n1];
        int R[] = new int[n2];

        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    public static void MergeSort(int arr[], int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            MergeSort(arr, l, m);
            MergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

		//Insertion Sort
    public static void InsertionSort(int[] array) {
        for (int j = 1; j < array.length; j++) {
            int key = array[j];
            int i = j - 1;
            while (i >= 0 && key < array[i]) {
                array[i + 1] = array[i];
                i--;
            }
            array[i + 1] = key;
        }
    }
		
		//Heap Sort
    public static void heapify(int arr[], int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            heapify(arr, n, largest);
        }
    }
	
    public static void HeapSort(int arr[]) {
        int n = arr.length;

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(arr, 0, i);
            heapify(arr, i, 0);
        }
    }
		
		//Counting Sort
    public static void counting(int[] ar, int minVal, int maxVal) {
        int sz = maxVal - minVal + 1;
        int[] b = new int[sz];
        for (int i = 0; i < ar.length; i++)
            b[ar[i] - minVal]++;
        for (int i = 0, k = 0; i < sz; i++) {
            while (b[i]-- > 0)
                ar[k++] = i + minVal;
        }
    }

    public static void CountingSort(int[] values) {
        int minValue = Integer.MAX_VALUE;
        int maxValue = Integer.MIN_VALUE;
        for (int i = 0; i < values.length; i++) {
            if (values[i] < minValue)
                minValue = values[i];
            if (values[i] > maxValue)
                maxValue = values[i];
        }
        counting(values, minValue, maxValue);
    }

		//Bubble Sort
    public static void BubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr, j, j + 1);
                }
            }
        }
    }

		//Utilidades
    public static void randomize(int[] arr) {
        Random rand = new Random();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(arr.length);
        }
    }

    public static void printArray(int[] arr) {
        for (int element : arr)
            System.out.printf("%s ", element);
        System.out.println();
    }

    public static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    public static void main(String[] args) {

			String nr = "Puntos1.txt";
			File archivo;
			FileReader fr;
			BufferedReader br;

			try{
				int elementos;
				int paso;
				int longitud;

				archivo=new File(nr);
				fr= new FileReader(archivo);
				br= new BufferedReader(fr);
				String intermedio=br.readLine();
				String[] inter2=intermedio.split("\\s+");

				elementos=Integer.parseInt(inter2[0]);
				
				intermedio=br.readLine();
				inter2=intermedio.split("\\s+");
				paso=Integer.parseInt(inter2[0]);
				longitud=elementos/paso;

				long[] x= new long[longitud];
				long[] y1= new long[longitud];

				for(int i=1;i<=longitud;i++){
					System.out.printf("numero "+i);
					x[i-1]=i*paso;
					String cadena=br.readLine();
					String[] data=cadena.split("\\s+");
					int[] arr = new int[i*paso];
					
					for(int j=0;j<(i*paso);j++){
						arr[j]=Integer.parseInt(data[j]);
					}

					long startTime = System.nanoTime();
		      BubbleSort(arr);
					long endTime = System.nanoTime() - startTime;
					y1[i-1]=endTime;					

				}


				String n = "BubbleSort.txt";
				File f;
				FileWriter w;
				BufferedWriter bw;
				PrintWriter wr;

				try{
					f=new File(n);
					w= new FileWriter(f);
					bw= new BufferedWriter(w);
					wr=new PrintWriter(bw);
					
					wr.write(x[0]+" "+y1[0]+"\n");
					for(int i=1;i<(longitud-1);i++){
						wr.append(x[i]+" "+y1[i]+"\n");
					}				
					wr.append(x[longitud-1]+" "+y1[longitud-1]+"");
					wr.close();
					bw.close();
				}catch(Exception e){
						System.out.printf("error en la escritura");
				}
				
				
				fr.close();
				br.close();
			}catch(Exception e){
					System.out.printf("error en la lectura");
			}				
				/*
				for(int i=1;i<=longitud;i++){
					


					startTime = System.nanoTime();
		      CountingSort(arr2);
		      //printArray(arr);
					endTime = System.nanoTime() - startTime;
					y2[i-1]=endTime;

					startTime = System.nanoTime();
		      HeapSort(arr3);
		      //printArray(arr);
					endTime = System.nanoTime() - startTime;
					y3[i-1]=endTime;

					startTime = System.nanoTime();					
		      InsertionSort(arr4);
		      //printArray(arr);
					endTime = System.nanoTime() - startTime;
					y4[i-1]=endTime;

					startTime = System.nanoTime();
		      MergeSort(arr5,0,i*paso-1);
		      //printArray(arr);
					endTime = System.nanoTime() - startTime;
					y5[i-1]=endTime;

					startTime = System.nanoTime();
		      QuickSort(arr6,0,i*paso-1);
		      //printArray(arr);
					endTime = System.nanoTime() - startTime;
					y6[i-1]=endTime;

					startTime = System.nanoTime();
		      SelectionSort(arr7);
		      //printArray(arr);
					endTime = System.nanoTime() - startTime;
					y7[i-1]=endTime;
			
				}

			String n = "BubbleSort.txt";
			File f;
			FileWriter w;
			BufferedWriter bw;
			PrintWriter wr;

			try{
				f=new File(n);
				w= new FileWriter(f);
				bw= new BufferedWriter(w);
				wr=new PrintWriter(bw);

				wr.write(x[0]+" "+y1[0]+"\n");
				for(int i=1;i<(longitud-1);i++){
					wr.append(x[i]+" "+y1[i]+"\n");
				}
				
				wr.append(x[longitud-1]+" "+y1[longitud-1]+"");

				wr.close();
				bw.close();
			}catch(Exception e){
					System.out.printf("error en la escritura");
			}


			String n2 = "CountingSort.txt";
			File f2;
			FileWriter w2;
			BufferedWriter bw2;
			PrintWriter wr2;

			try{
				f2=new File(n2);
				w2= new FileWriter(f2);
				bw2= new BufferedWriter(w2);
				wr2=new PrintWriter(bw2);

				wr2.write(x[0]+" "+y2[0]+"\n");
				for(int i=1;i<(longitud-1);i++){
					wr2.append(x[i]+" "+y2[i]+"\n");
				}
				
				wr2.append(x[longitud-1]+" "+y2[longitud-1]+"");

				wr2.close();
				bw2.close();
			}catch(Exception e){
					System.out.printf("error en la escritura");
			}



			String n3 = "HeapSort.txt";
			File f3;
			FileWriter w3;
			BufferedWriter bw3;
			PrintWriter wr3;

			try{
				f3=new File(n3);
				w3= new FileWriter(f3);
				bw3= new BufferedWriter(w3);
				wr3=new PrintWriter(bw3);

				wr3.write(x[0]+" "+y3[0]+"\n");
				for(int i=1;i<(longitud-1);i++){
					wr3.append(x[i]+" "+y3[i]+"\n");
				}
				
				wr3.append(x[longitud-1]+" "+y3[longitud-1]+"");

				wr3.close();
				bw3.close();
			}catch(Exception e){
					System.out.printf("error en la escritura");
			}



			String n4 = "InsertionSort.txt";
			File f4;
			FileWriter w4;
			BufferedWriter bw4;
			PrintWriter wr4;

			try{
				f4=new File(n4);
				w4= new FileWriter(f4);
				bw4= new BufferedWriter(w4);
				wr4=new PrintWriter(bw4);

				wr4.write(x[0]+" "+y4[0]+"\n");
				for(int i=1;i<(longitud-1);i++){
					wr4.append(x[i]+" "+y4[i]+"\n");
				}
				
				wr4.append(x[longitud-1]+" "+y4[longitud-1]+"");

				wr4.close();
				bw4.close();
			}catch(Exception e){
					System.out.printf("error en la escritura");
			}


			String n5 = "MergeSort.txt";
			File f5;
			FileWriter w5;
			BufferedWriter bw5;
			PrintWriter wr5;

			try{
				f5=new File(n5);
				w5= new FileWriter(f5);
				bw5= new BufferedWriter(w5);
				wr5=new PrintWriter(bw5);

				wr5.write(x[0]+" "+y5[0]+"\n");
				for(int i=1;i<(longitud-1);i++){
					wr5.append(x[i]+" "+y5[i]+"\n");
				}
				
				wr5.append(x[longitud-1]+" "+y5[longitud-1]+"");

				wr5.close();
				bw5.close();
			}catch(Exception e){
					System.out.printf("error en la escritura");
			}


			String n6 = "QuickSort.txt";
			File f6;
			FileWriter w6;
			BufferedWriter bw6;
			PrintWriter wr6;

			try{
				f6=new File(n6);
				w6= new FileWriter(f6);
				bw6= new BufferedWriter(w6);
				wr6=new PrintWriter(bw6);

				wr6.write(x[0]+" "+y6[0]+"\n");
				for(int i=1;i<(longitud-1);i++){
					wr6.append(x[i]+" "+y6[i]+"\n");
				}
				
				wr6.append(x[longitud-1]+" "+y6[longitud-1]+"");

				wr6.close();
				bw6.close();
			}catch(Exception e){
					System.out.printf("error en la escritura");
			}


			String n7 = "SelectionSort.txt";
			File f7;
			FileWriter w7;
			BufferedWriter bw7;
			PrintWriter wr7;

			try{
				f7=new File(n7);
				w7= new FileWriter(f7);
				bw7= new BufferedWriter(w7);
				wr7=new PrintWriter(bw7);

				wr7.write(x[0]+" "+y7[0]+"\n");
				for(int i=1;i<(longitud-1);i++){
					wr7.append(x[i]+" "+y7[i]+"\n");
				}
				
				wr7.append(x[longitud-1]+" "+y7[longitud-1]+"");

				wr7.close();
				bw7.close();
			}catch(Exception e){
					System.out.printf("error en la escritura");
			}
			*/



    }
}
