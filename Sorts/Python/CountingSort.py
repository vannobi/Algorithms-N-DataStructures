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
