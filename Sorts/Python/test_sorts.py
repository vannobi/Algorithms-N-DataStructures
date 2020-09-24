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
import numpy as np

results = None
current_array = None
sizes = None
fw = None

bigO_square = {'Bubble Sort', 'Insertion Sort', 'Selection Sort'}


def randomize(size):
    newlist = [0]*size
    for i in range(size):
        newlist[i] = random.randint(0, size*7)
    return newlist


def write_results(alg_name):
    fw.write('{0},'.format(alg_name))
    for i in range(len(results)):
        res = float('{:.5}'.format(results[i]))
        if i != len(results)-1:
            fw.write('{0},'.format(res))
        else:
            fw.write('{0}\n'.format(res))


def test_sort(sort_algo, alg_name):
    global results, sizes, current_array, fw
    cycles = 10
    if alg_name in bigO_square:
        cycles = 1

    for cycle in range(cycles):
        print('Cycle', cycle)
        for i in range(len(sizes)):
            current_array = None
            current_array = [0]*sizes[i]
            freader = open(
                './utils/random/{0}-{1}.txt'.format(sizes[i], cycle), 'r', encoding='utf-8')
            idx = 0
            for line in freader:
                current_array[idx] = int(line)
                idx += 1
            freader.close()
            if sort_algo != None:
                startTime = time.time()
                sort_algo(current_array)
                endTime = time.time()
            else:
                startTime = time.time()
                current_array.sort()
                endTime = time.time()
            # Logs
            results[i] += endTime-startTime
            # results[i] = float('{:.5}'.format(results[i]))
            print(float('{:.5}'.format(endTime-startTime)), 'sec')
    results /= cycles
    write_results(alg_name)
    results = np.array([0.]*len(results))


class TestCalc(unittest.TestCase):
    # def test_BubbleSort(self):
    #     print('Bubble Sort :: Ω(n)	Θ(n^2)	O(n^2)')
    #     test_sort(BS.BubbleSort, "Bubble Sort")

    def test_CountingSort(self):
        print('Counting Sort :: Ω(n+k)	Θ(n+k)	O(n+k)')
        test_sort(CS.CountingSort, "Counting Sort")

    # def test_HeapSort(self):
    #     print('Heap Sort :: Ω(n log(n))	Θ(n log(n))	O(n log(n))')
    #     test_sort(HS.HeapSort, "Heap Sort")

    # def test_InsertionSort(self):
    #     print('Insertion Sort :: Ω(n) Θ(n^2) O(n^2)')
    #     test_sort(IS.InsertionSort, "Insertion Sort")

    # def test_MergeSort(self):
    #     print('Merge Sort :: Ω(n log(n)) Θ(n log(n)) O(n log(n))')
    #     test_sort(MS.MergeSort, "Merge Sort")

    def test_QuickSort(self):
        print('Quick Sort :: Ω(n log(n)) Θ(n log(n)) O(n^2)')
        test_sort(QS.QuickSort, "Quick Sort")

    # def test_SelectionSort(self):
    #     print('Selection Sort :: Ω(n^2) Θ(n^2) O(n^2)')
    #     test_sort(SS.SelectionSort, "Selection Sort")

    def test_SortNative(self):
        print('Python Sort')
        test_sort(None, "Python Sort")


if __name__ == '__main__':
    f = open('./utils/number-settings.txt', 'r', encoding='utf-8')
    fw = open('./results/csv/python-results.csv', 'w', encoding='utf-8')
    line_1 = int(f.readline())
    results = np.array([0.]*line_1)
    sizes = [0]*line_1
    index = 0
    for line in f:
        sizes[index] = int(line)
        index += 1
    f.close()
    unittest.main()
    fw.close()
