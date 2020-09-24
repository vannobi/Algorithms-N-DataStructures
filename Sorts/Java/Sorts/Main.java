package Sorts;

import static Sorts.Utils.*;
import java.io.FileReader;
// import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedReader;

public class Main {
    static void reader() {
        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new FileReader("./utils/number-settings.txt"));
            String line = reader.readLine();
            while (line != null) {
                System.out.println(line);
                line = reader.readLine();
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        BubbleSort BS = new BubbleSort();
        CountingSort CS = new CountingSort();
        HeapSort HS = new HeapSort();
        InsertionSort IS = new InsertionSort();
        MergeSort MS = new MergeSort();
        QuickSort QS = new QuickSort();
        SelectionSort SS = new SelectionSort();
        reader();
        // int[] arr = new int[10];
        // randomize(arr);
        // BS.sort(arr);
        // printArray(arr);
    }
}
