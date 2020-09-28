from time import time

def CountingSort(collection):
    min_item = collection[0]  # min(collection)
    max_item = collection[0]  # max(collection)

    for elem in collection:
        if min_item > elem:
            min_item = elem
        if max_item < elem:
            max_item = elem

    counting_arr_length = max_item - min_item+1
    counting_arr = [0]*counting_arr_length
    # counting occurrences
    for i in range(len(collection)):
        counting_arr[collection[i]-min_item] += 1

    k = 0
    # traverse counting_arr
    # rebuild arr
    for i in range(counting_arr_length):
        while counting_arr[i] > 0:
            counting_arr[i] -= 1
            collection[k] = i + min_item
            k += 1
    return collection

f = open("Puntos1.txt", "r")
w = open("CountingSort.txt","w")

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
	CountingSort(arr)
	elapsed_time = time()-start_time
	w.write(str(i*paso)+".00 "+str(elapsed_time*1000000000)+"\n")

w.close()
f.close()
