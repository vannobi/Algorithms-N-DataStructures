def CountingSort(collection):
    min_item = min(collection)
    max_item = max(collection)

    counting_arr_length = max_item - min_item+1
    counting_arr = [0]*counting_arr_length
    # counting occurrences
    for i in range(len(collection)):
        counting_arr[collection[i]-min_item] += 1
    print(counting_arr)

    k = 0
    # traverse counting_arr
    # rebuild arr
    for i in range(counting_arr_length):
        while counting_arr[i] > 0:
            counting_arr[i] -= 1
            collection[k] = i + min_item
            k += 1
        print(counting_arr)
    return collection
