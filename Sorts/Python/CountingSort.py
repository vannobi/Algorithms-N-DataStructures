def CountingSort(collection):
    if collection == []:
        return []
    size = len(collection)
    max_item = max(collection)
    min_item = min(collection)
    counting_arr_length = max_item-min_item+1
    counting_arr = [0]*counting_arr_length

# count occurrences
    for number in collection:
        counting_arr[number - min_item] += 1

# index pos
    for i in range(1, counting_arr_length):
        counting_arr[i] = counting_arr[i] + counting_arr[i - 1]
    print(counting_arr)
    out = [0]*size

#  placing
    for i in reversed(range(0, size)):
        out[counting_arr[collection[i] - min_item] - 1] = collection[i]
        counting_arr[collection[i] - min_item] -= 1
    print(out)
    return out
