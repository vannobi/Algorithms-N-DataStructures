package Sorts;

import static Sorts.Utils.*;
import java.io.*;
import java.io.FileReader;
// import java.io.FileNotFoundException;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashMap;
import java.io.FileWriter;
import java.io.BufferedReader;

public class Main {
    static String SETTINGS_PATH = "./utils/number-settings.txt";
    static String RANDOM_PATH = "./utils/random/";
    static String CSV_PATH = "./results/csv/java-results.csv";
    static int MAX_CYCLES = 10;
    static HashMap<String, ArrayList<Double>> results = new HashMap<String, ArrayList<Double>>();
    static ArrayList<Integer> settings = null;
    static ArrayList<String> algorithms = null;

    static ArrayList<Integer> readSettings() {
        ArrayList<Integer> res = null;
        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new FileReader("./utils/number-settings.txt"));
            String line = reader.readLine();
            Integer size = Integer.parseInt(line);
            res = new ArrayList<Integer>(size);
            line = reader.readLine();
            while (line != null) {
                // System.out.println(line);
                res.add(Integer.parseInt(line));
                line = reader.readLine();
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return res;
    }

    static int[] getNextArray(int size, int curreCycle) {
        int res[] = new int[size];
        String path = RANDOM_PATH + Integer.toString(size) + "-" + Integer.toString(curreCycle) + ".txt";
        // System.out.println(path);
        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new FileReader(path));
            String line = reader.readLine();
            int i = 0;
            while (line != null && i < size) {
                res[i++] = Integer.parseInt(line);
                // System.out.println(line);
                line = reader.readLine();
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        // System.out.println("length: " + res.length);
        return res;
    }

    static void doCycles(int size, int cycles, String name, int currIndex) {
        CountingSort CS = new CountingSort();
        BubbleSort BS = new BubbleSort();
        HeapSort HS = new HeapSort();
        InsertionSort IS = new InsertionSort();
        MergeSort MS = new MergeSort();
        QuickSort QS = new QuickSort();
        SelectionSort SS = new SelectionSort();
        for (int curreCycle = 0; curreCycle < cycles; curreCycle++) {
            int nextArr[] = getNextArray(size, curreCycle);
            double elapsedTime = 0;
            if (name == "Bubble Sort") {
                long start = System.nanoTime();
                BS.sort(nextArr);
                long end = System.nanoTime();
                elapsedTime = (end - start) / 1e9;
                System.out.println(elapsedTime + " sec");
            } else if (name == "Counting Sort") {
                long start = System.nanoTime();
                CS.sort(nextArr);
                long end = System.nanoTime();
                elapsedTime = (end - start) / 1e9;
                System.out.println(elapsedTime + " sec");
            } else if (name == "Heap Sort") {
                long start = System.nanoTime();
                HS.sort(nextArr);
                long end = System.nanoTime();
                elapsedTime = (end - start) / 1e9;
                System.out.println(elapsedTime + " sec");
            } else if (name == "Insertion Sort") {
                long start = System.nanoTime();
                IS.sort(nextArr);
                long end = System.nanoTime();
                elapsedTime = (end - start) / 1e9;
                System.out.println(elapsedTime + " sec");
            } else if (name == "Merge Sort") {
                long start = System.nanoTime();
                MS.sort(nextArr, 0, nextArr.length - 1);
                long end = System.nanoTime();
                elapsedTime = (end - start) / 1e9;
                System.out.println(elapsedTime + " sec");
            } else if (name == "Quick Sort") {
                long start = System.nanoTime();
                QS.sort(nextArr, 0, nextArr.length - 1);
                long end = System.nanoTime();
                elapsedTime = (end - start) / 1e9;
                System.out.println(elapsedTime + " sec");
            } else if (name == "Selection Sort") {
                long start = System.nanoTime();
                SS.sort(nextArr);
                long end = System.nanoTime();
                elapsedTime = (end - start) / 1e9;
                System.out.println(elapsedTime + " sec");
            }
            ArrayList<Double> items = results.get(name);
            Double item = items.get(currIndex);
            item += elapsedTime;
            items.set(currIndex, item);
        }
        ArrayList<Double> items = results.get(name);
        Double item = items.get(currIndex);
        item /= cycles;
        System.out.println("AVG: " + item);
        items.set(currIndex, item);
    }

    static void testSort(String name) {
        System.out.println(">> >> " + name);
        int Cycles = name == "Bubble Sort" || name == "Insertion Sort" || name == "Selection Sort" ? 1 : MAX_CYCLES;
        for (int i = 0; i < settings.size(); i++) {
            doCycles(settings.get(i), Cycles, name, i);
        }
    }

    static void writResults() {
        try {
            // File csv = new File(CSV_PATH);
            FileWriter csvWriter = new FileWriter(CSV_PATH);
            String contents = "";
            for (int i = 0; i < algorithms.size(); i++) {
                String algName = algorithms.get(i);
                contents += algName + ",";
                ArrayList<Double> itemList = results.get(algName);
                for (int j = 0; j < settings.size(); j++) {
                    contents += Double.toString(itemList.get(j));
                    if (j + 1 != settings.size()) {
                        contents += ",";
                    } else {
                        contents += "\n";
                    }

                }
            }
            csvWriter.write(contents);
            csvWriter.close();
            System.out.println("Results written");
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    static int[] randomArray(int size) {
        int[] res = new int[size];
        for (int i = 0; i < res.length; i++) {
            res[i] = (int) ((Math.random() * (size - 0)) + 0);
        }
        return res;
    }

    public static void main(String[] args) {
        settings = readSettings();
        algorithms = new ArrayList<String>(7);
        algorithms.add("Bubble Sort");
        algorithms.add("Counting Sort");
        algorithms.add("Heap Sort");
        algorithms.add("Insertion Sort");
        algorithms.add("Merge Sort");
        algorithms.add("Quick Sort");
        algorithms.add("Selection Sort");
        for (int i = 0; i < algorithms.size(); i++) {
            results.put(algorithms.get(i), new ArrayList<Double>(settings.size()));
            ArrayList<Double> itemsList = results.get(algorithms.get(i));
            for (int j = 0; j < settings.size(); j++) {
                itemsList.add(0.0);
            }
        }
        // testSort("Bubble Sort");
        testSort("Quick Sort"); // y
        testSort("Counting Sort"); // y
        testSort("Merge Sort");// y
        // testSort("Counting Sort");
        testSort("Heap Sort");// y
        // testSort("Insertion Sort");
        writResults();
        // System.out.println(results);
    }
}
