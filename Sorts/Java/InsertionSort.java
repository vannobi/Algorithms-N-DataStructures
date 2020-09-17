class InsertionSort {
    public int[] sort(int[] array) {
        for (int j = 1; j < array.length; j++) {
            int key = array[j];
            int i = j - 1;
            while (i >= 0 && key < array[i]) {
                array[i + 1] = array[i];
                i--;
            }
            array[i + 1] = key;
        }
        return array;
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
        int[] integers = {4, 23, 6, 78, 1, 54, 231, 9, 12};
        InsertionSort sort = new InsertionSort();
        sort.sort(integers);
        // Output => 1 4 6 9 12 23 54 78 231
        sort.print(integers);
    }
}