from time import time

def MergeSort(array):
    if len(array) > 1:
        #  r is the point where the array is divided into two subarrays
        r = len(array)//2
        L = array[:r]
        M = array[r:]
        # Sort the two halves
        MergeSort(L)
        MergeSort(M)
        i = j = k = 0
        # Until we reach either end of either L or M, pick larger among
        # elements L and M and place them in the correct position at A[p..r]
        while i < len(L) and j < len(M):
            if L[i] < M[j]:
                array[k] = L[i]
                i += 1
            else:
                array[k] = M[j]
                j += 1
            k += 1
        # When we run out of elements in either L or M,
        # pick up the remaining elements and put in A[p..r]
        while i < len(L):
            array[k] = L[i]
            i += 1
            k += 1
        while j < len(M):
            array[k] = M[j]
            j += 1
            k += 1

f = open("Puntos1.txt", "r")
w = open("MergeSort.txt","w")

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
	MergeSort(arr)
	elapsed_time = time()-start_time
	w.write(str(i*paso)+".00 "+str(elapsed_time*1000000000)+"\n")

w.close()
f.close()
