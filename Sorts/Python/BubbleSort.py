def BubbleSort(collection):
    length = len(collection)
    for i in range(length - 1):
        for j in range(length - 1 - i):
            if collection[j] > collection[j + 1]:
                collection[j], collection[j +
                                          1] = collection[j + 1], collection[j]
    return collection


if __name__ == "__main__":
    arr = [6, 5, 4, 3, 7]
    BubbleSort(arr)
    print(arr)
