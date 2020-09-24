#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../utils/utils.hpp"
#include "./src/BubbleSort.hpp"
#include "./src/CountingSort.hpp"
#include "./src/HeapSort.hpp"
#include "./src/InsertionSort.hpp"
#include "./src/MergeSort.hpp"
#include "./src/QuickSort.hpp"
#include "./src/SelectionSort.hpp"

using namespace std;

string OUTPUT_CSV_PATH = "./results/csv/c-results.csv";

auto settings = readSettings();
map<string, vector<double>> results;

void doCycles(int size, int cycles, string name, size_t currIndex) {
  for (int currCycle = 0; currCycle < cycles; currCycle++) {
    int* nextArr = getNextArray(size, currCycle);
    double elapsedTime;
    if (name == "Bubble Sort") {
      {
        Timer time(&elapsedTime);
        BS::sort(nextArr, size);
      }
    } else if (name == "Counting Sort") {
      {
        Timer time(&elapsedTime);
        CS::sort(nextArr, size);
      }
    } else if (name == "Heap Sort") {
      {
        Timer time(&elapsedTime);
        HS::sort(nextArr, size);
      }
    } else if (name == "Insertion Sort") {
      {
        Timer time(&elapsedTime);
        IS::sort(nextArr, size);
      }
    } else if (name == "Merge Sort") {
      {
        Timer time(&elapsedTime);
        MS::sort(nextArr, 0, size - 1);
      }
    } else if (name == "Quick Sort") {
      {
        Timer time(&elapsedTime);
        QS::sort(nextArr, 0, size - 1);
      }
      // printLn(nextArr, size);
    } else if (name == "Selection Sort") {
      {
        Timer time(&elapsedTime);
        SS::sort(nextArr, size);
      }
    }
    results[name][currIndex] += elapsedTime;
    delete[] nextArr;
    nextArr = nullptr;
  }
  results[name][currIndex] /= cycles;
  cout << "AVG: " << results[name][currIndex] << '\n';
}

void testSort(string name) {
  cout << name << '\n';
  int Cycles = name == "Bubble Sort" || name == "Insertion Sort" ||
                       name == "Selection Sort"
                   ? 1
                   : 10;
  for (size_t i = 0; i < settings.size(); i++) {
    doCycles(settings[i], Cycles, name, i);
  }
}

int main() {
  auto Algorithms = {"Bubble Sort",    "Counting Sort", "Heap Sort",
                     "Insertion Sort", "Merge Sort",    "Quick Sort",
                     "Selection Sort"};
  for (auto& name : Algorithms) {
    results[name] = vector<double>(settings.size());
  }
  testSort("Quick Sort");
  testSort("Counting Sort");
  testSort("Merge Sort");
  // testSort("Counting Sort");
  testSort("Heap Sort");
  // testSort("Insertion Sort");
  string buff;
  for (auto& name : Algorithms) {
    buff += name;
    buff += ",";
    printLn(results[name], buff);
  }
  ofstream ResultsWritter(OUTPUT_CSV_PATH.c_str());
  ResultsWritter << buff;
  ResultsWritter.close();
  return 0;
}