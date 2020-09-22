package Sorts;

import java.util.Random;

public class Utils {
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
}
