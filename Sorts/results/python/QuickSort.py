from time import time

def partition(arr, low, high):
    i = (low-1)         # index of smaller element
    pivot = arr[high]     # pivot
    for j in range(low, high):
        if arr[j] <= pivot:
            i = i+1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i+1)


def QuickSort(arr):
    def quickSort(arr, low, high):
        if len(arr) == 1:
            return arr
        if low < high:
            # at right place
            pi = partition(arr, low, high)
            quickSort(arr, low, pi-1)
            quickSort(arr, pi+1, high)
    quickSort(arr, 0, len(arr)-1)
    return arr

f = open("Puntos1.txt", "r")
w = open("QuickSort.txt","w")

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
	QuickSort(arr)
	elapsed_time = time()-start_time
	w.write(str(i*paso)+".00 "+str(elapsed_time*1000000000)+"\n")

w.close()
f.close()
