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


def randomize(list: list):
    for i in range(len(list)):
        list[i] = random.randint(0, len(list)*7)


def write_results():
    for i in range(len(results)):
        if i != len(results)-1:
            fw.write('{0},'.format(str(results[i])))
        else:
            fw.write('{0}\n'.format(str(results[i])))


def test_sort(sort_algo):
    global results, sizes, current_array, fw
    for i in range(len(sizes)):
        current_array = [0]*sizes[i]
        randomize(current_array)
        startTime = time.time()
        sort_algo(current_array)
        endTime = time.time()
        results[i] = float('{:.4}'.format(endTime-startTime))
        print(results[i], 'sec')
    write_results()


class TestCalc(unittest.TestCase):
    def test_BubbleSort(self):
        print('Bubble Sort :: Ω(n)	Θ(n^2)	O(n^2)')
        test_sort(BS.BubbleSort)

    def test_CountingSort(self):
        print('Counting Sort :: Ω(n+k)	Θ(n+k)	O(n+k)')
        test_sort(CS.CountingSort)

    def test_HeapSort(self):
        print('Heap Sort :: Ω(n log(n))	Θ(n log(n))	O(n log(n))')
        test_sort(HS.HeapSort)

    def test_InsertionSort(self):
        print('Insertion Sort :: Ω(n) Θ(n^2) O(n^2)')
        test_sort(IS.InsertionSort)

    def test_MergeSort(self):
        print('Merge Sort :: Ω(n log(n)) Θ(n log(n)) O(n log(n))')
        test_sort(MS.MergeSort)

    def test_QuickSort(self):
        print('Quick Sort :: Ω(n log(n)) Θ(n log(n)) O(n^2)')
        test_sort(QS.QuickSort)

    def test_SelectionSort(self):
        print('Selection Sort :: Ω(n^2) Θ(n^2) O(n^2)')
        test_sort(SS.SelectionSort)


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
