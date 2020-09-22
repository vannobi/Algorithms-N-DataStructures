package Sorts;

import static Sorts.Utils.*;

public class Main {

    public static void main(String[] args) {
        BubbleSort BS = new BubbleSort();
        CountingSort CS = new CountingSort();
        HeapSort HS = new HeapSort();
        InsertionSort IS = new InsertionSort();
        MergeSort MS = new MergeSort();
        QuickSort QS = new QuickSort();
        SelectionSort SS = new SelectionSort();
        int[] arr = new int[10];
        randomize(arr);
        BS.sort(arr);
        printArray(arr);
    }
}
