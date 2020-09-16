import matplotlib.pyplot as plt

all_algo = ['Bubble Sort',
            'Counting Sort',
            'Heap Sort',
            'Insertion Sort',
            'Merge Sort',
            'Quick Sort',
            'Selection Sort']

nlogn_n = [all_algo[1], all_algo[2], all_algo[4], all_algo[5]]


if __name__ == "__main__":
    f_python = open('Python/[python]-results.txt', 'r', encoding='utf-8')
    python_results = []
    sizes = None

    for line in f_python:
        res = line.split(',')
        python_results.append([float(e) for e in res])
    print(python_results)

    f_sett = open('test-settings.txt', 'r', encoding='utf-8')
    sizes = [0] * int(f_sett.readline())
    for i in range(len(sizes)):
        sizes[i] = int(f_sett.readline())
    print(sizes)

    f_python.close()
    f_sett.close()

    # plt.plot(sizes, python_results[0])
    plt.plot(sizes, python_results[1])
    plt.plot(sizes, python_results[2])
    # plt.plot(sizes, python_results[3])
    plt.plot(sizes, python_results[4])
    plt.plot(sizes, python_results[5])
    # plt.plot(sizes, python_results[6])
    plt.xlabel('size')
    plt.ylabel('time')
    # plt.legend([order[0], order[3], order[6]])
    plt.legend(all_algo)
    plt.legend(nlogn_n)
    plt.show()
    plt.savefig('python-performance.png')
