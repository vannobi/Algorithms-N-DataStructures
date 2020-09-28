from time import time

def heapify(unsorted, index, heap_size):
    largest = index
    left_index = 2 * index + 1
    right_index = 2 * index + 2
    if left_index < heap_size and unsorted[left_index] > unsorted[largest]:
        largest = left_index

    if right_index < heap_size and unsorted[right_index] > unsorted[largest]:
        largest = right_index

    if largest != index:
        unsorted[largest], unsorted[index] = unsorted[index], unsorted[largest]
        heapify(unsorted, largest, heap_size)


def HeapSort(unsorted):
    n = len(unsorted)
    for i in range(n // 2 - 1, -1, -1):
        heapify(unsorted, i, n)
    for i in range(n - 1, 0, -1):
        unsorted[0], unsorted[i] = unsorted[i], unsorted[0]
        heapify(unsorted, 0, i)
    return unsorted

f = open("Puntos1.txt", "r")
w = open("HeapSort.txt","w")

NUM_ELEMENTOS=int(f.readline())
paso=int(f.readline())
NUM_PUNTOS=int(NUM_ELEMENTOS/paso)
for i in range(1,(NUM_PUNTOS+1)):
	print(i)
	auxX=f.readline()
	auxX2=auxX.split()
	arr=[]
	for m in auxX2:
		arr.append(int(m))
	start_time = time()
	HeapSort(arr)
	elapsed_time = time()-start_time
	w.write(str(i*paso)+".00 "+str(elapsed_time*1000000000)+"\n")

w.close()
f.close()
