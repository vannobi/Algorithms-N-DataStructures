class SelectionSort {
    
    public void swap(int[] arr, int i, int j) {
       int temp = arr[i];
       arr[i] = arr[j];
       arr[j] = temp;
    }
    
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
    void print(int arr[]) 
    { 
        int n = arr.length; 
        for (int i=0; i<n; ++i) 
            System.out.print(arr[i] + " "); 
        System.out.println(); 
    } 
    // Driver Program
    public static void main(String[] args) {
        int[] arr = {4, 23, 6, 78, 1, 54, 231, 9, 12};
        SelectionSort selectionSort = new SelectionSort();
        int[] sorted = selectionSort.sort(arr);
        // Output => 1	  4	 6	9	12	23	54	78	231
        selectionSort.print(sorted);
    }
}