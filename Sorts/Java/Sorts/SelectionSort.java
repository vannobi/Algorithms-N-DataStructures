package Sorts;

import static Sorts.Utils.*;

class SelectionSort {

    public int[] sort(int[] arr) {
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
        return arr;
    }
}