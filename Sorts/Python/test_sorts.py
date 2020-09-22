import BubbleSort as BS
import CountingSort as CS
import HeapSort as HS
import InsertionSort as IS
import MergeSort as MS
import QuickSort as QS
import SelectionSort as SS

import unittest
import random
import time

results = None
current_array = None
sizes = None
fw = None


def randomize(size):
    newlist = [0]*size
    for i in range(size):
        newlist[i] = random.randint(0, size*7)
    return newlist


def write_results(alg_name):
    fw.write('[{0}]\n'.format(alg_name))
    for i in range(len(results)):
        if i != len(results)-1:
            fw.write('{0},'.format(results[i]))
        else:
            fw.write('{0}\n'.format(results[i]))


def test_sort(sort_algo, alg_name, action):
    global results, sizes, current_array, fw
    for i in range(len(sizes)):
        current_array = None
        # generate num
        if action == "g":
            current_array = randomize(current_array)
        # Or read files
        if action == "r":
            current_array = [0]*sizes[i]
            freader = open(
                '../Numbers/{0}.txt'.format(sizes[i]), 'r', encoding='utf-8')
            idx = 0
            for line in freader:
                current_array[idx] = int(line)
                idx += 1
            freader.close()
        startTime = time.time()
        sort_algo(current_array)
        endTime = time.time()
        # Logs
        results[i] = float('{:.4}'.format(endTime-startTime))
        print(results[i], 'sec')
    write_results(alg_name)


class TestCalc(unittest.TestCase):
    def test_BubbleSort(self):
        print('Bubble Sort :: Ω(n)	Θ(n^2)	O(n^2)')
        test_sort(BS.BubbleSort, "BubbleSort", "r")

    def test_CountingSort(self):
        print('Counting Sort :: Ω(n+k)	Θ(n+k)	O(n+k)')
        test_sort(CS.CountingSort, "CountingSort", 'r')

    def test_HeapSort(self):
        print('Heap Sort :: Ω(n log(n))	Θ(n log(n))	O(n log(n))')
        test_sort(HS.HeapSort, "HeapSort", "r")

    def test_InsertionSort(self):
        print('Insertion Sort :: Ω(n) Θ(n^2) O(n^2)')
        test_sort(IS.InsertionSort, "InsertionSort", "r")

    def test_MergeSort(self):
        print('Merge Sort :: Ω(n log(n)) Θ(n log(n)) O(n log(n))')
        test_sort(MS.MergeSort, "MergeSort", "r")

    def test_QuickSort(self):
        print('Quick Sort :: Ω(n log(n)) Θ(n log(n)) O(n^2)')
        test_sort(QS.QuickSort, "QuickSort", "r")

    def test_SelectionSort(self):
        print('Selection Sort :: Ω(n^2) Θ(n^2) O(n^2)')
        test_sort(SS.SelectionSort, "SelectionSort", "r")


if __name__ == '__main__':
    f = open('../test-settings.txt', 'r', encoding='utf-8')
    fw = open('[python]-results.txt', 'w', encoding='utf-8')
    line_1 = int(f.readline())
    results = [0]*line_1
    sizes = [0]*line_1
    index = 0
    for line in f:
        sizes[index] = int(line)
        index += 1
    f.close()
    unittest.main()
    fw.close()
