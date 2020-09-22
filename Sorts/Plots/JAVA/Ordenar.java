//javac Ordenar.java
//java Ordenar

import java.util.Random;

public class Ordenar{

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

				int longitud=10;

				for(int i=1;i<longitud;i++){

		      int[] arr = new int[10];
		      int[] arr2 = new int[10];
		      int[] arr3 = new int[10];
		      int[] arr4 = new int[10];
		      int[] arr5 = new int[10];
		      int[] arr6 = new int[10];
		      int[] arr7 = new int[10];
					
					randomize(arr);
					randomize(arr2);
					randomize(arr3);
					randomize(arr4);
					randomize(arr5);
					randomize(arr6);
					randomize(arr7);

					long startTime = System.nanoTime();
		      BubbleSort(arr);
					long endTime = System.nanoTime() - startTime;
					System.out.printf("%s \n",endTime);

					startTime = System.nanoTime();
		      CountingSort(arr2);
		      //printArray(arr);
					endTime = System.nanoTime() - startTime;
					System.out.printf("%s \n",endTime);

					startTime = System.nanoTime();
		      HeapSort(arr3);
		      //printArray(arr);
					endTime = System.nanoTime() - startTime;
					System.out.printf("%s \n",endTime);

					startTime = System.nanoTime();					
		      InsertionSort(arr4);
		      //printArray(arr);
					endTime = System.nanoTime() - startTime;
					System.out.printf("%s \n",endTime);

					startTime = System.nanoTime();
		      MergeSort(arr5,0,9);
		      //printArray(arr);
					endTime = System.nanoTime() - startTime;
					System.out.printf("%s \n",endTime);

					startTime = System.nanoTime();
		      QuickSort(arr6,0,9);
		      //printArray(arr);
					endTime = System.nanoTime() - startTime;
					System.out.printf("%s \n",endTime);

					startTime = System.nanoTime();
		      SelectionSort(arr7);
		      //printArray(arr);
					endTime = System.nanoTime() - startTime;
					System.out.printf("%s \n",endTime);				
				}

    }
}
