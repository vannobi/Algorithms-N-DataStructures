import matplotlib.pyplot as plt
import csv

all_algo = ['Bubble Sort',  # 0
            'Counting Sort',  # 1
            'Heap Sort',  # 2
            'Insertion Sort',  # 3
            'Merge Sort',  # 4
            'Quick Sort',  # 5
            'Selection Sort']  # 6

nlogn_n = [all_algo[1], all_algo[2], all_algo[4], all_algo[5]]


def read_results(path):
    results = dict()
    with open(path) as python_results_file:
        readCSV = csv.reader(python_results_file, delimiter=',')
        for row in readCSV:
            algorithm_name = row[0]
            results[row[0]] = [float(num) for num in row[1:]]
    return results


if __name__ == "__main__":

    f_sett = open('./utils/number-settings.txt', 'r', encoding='utf-8')
    sizes = [0] * int(f_sett.readline())
    for i in range(len(sizes)):
        sizes[i] = int(f_sett.readline())
    # print(sizes)
    f_sett.close()

    # fetching results
    python_results = read_results('./results/csv/python-results.csv')
    c_results = read_results('./results/csv/c-results.csv')
    java_results = read_results('./results/csv/java-results.csv')

    # SAVING PLOT FOR PYTHON
    # plt.plot(sizes, python_results['Bubble Sort'])
    plt.plot(sizes, python_results['Counting Sort'])
    plt.plot(sizes, python_results['Heap Sort'])
    # plt.plot(sizes, python_results['Insertion Sort'])
    plt.plot(sizes, python_results['Merge Sort'])
    plt.plot(sizes, python_results['Quick Sort'])
    # plt.plot(sizes, python_results['Selection Sort'])
    # plt.plot(sizes, python_results['Python Sort'])
    plt.xlabel('size')
    plt.ylabel('time')
    plt.legend(nlogn_n)
    plt.show()
    plt.savefig('./results/img/python-performance.png')
    plt.close()
    plt.clf()

    # SAVING PLOT FOR C++
    # plt.plot(sizes, c_results['Bubble Sort'])
    plt.plot(sizes, c_results['Counting Sort'])
    plt.plot(sizes, c_results['Heap Sort'])
    # plt.plot(sizes, c_results['Insertion Sort'])
    plt.plot(sizes, c_results['Merge Sort'])
    plt.plot(sizes, c_results['Quick Sort'])
    # plt.plot(sizes, c_results['Selection Sort'])
    plt.xlabel('size')
    plt.ylabel('time')
    plt.legend(nlogn_n)
    plt.show()
    plt.savefig('./results/img/c-performance.png')
    plt.close()
    plt.clf()

    # SAVING PLOT FOR Java
    # plt.plot(sizes, c_results['Bubble Sort'])
    plt.plot(sizes, java_results['Counting Sort'])
    plt.plot(sizes, java_results['Heap Sort'])
    # plt.plot(sizes, java_results['Insertion Sort'])
    plt.plot(sizes, java_results['Merge Sort'])
    plt.plot(sizes, java_results['Quick Sort'])
    # plt.plot(sizes, java_results['Selection Sort'])
    plt.xlabel('size')
    plt.ylabel('time')
    plt.legend(nlogn_n)
    plt.show()
    plt.savefig('./results/img/java-performance.png')
    plt.close()
    plt.clf()
    # JAVA vs C++

    # plt.plot(sizes, c_results['Bubble Sort'])
    plt.plot(sizes, c_results['Counting Sort'])
    plt.plot(sizes, c_results['Heap Sort'])
    # plt.plot(sizes, c_results['Insertion Sort'])
    plt.plot(sizes, c_results['Merge Sort'])
    plt.plot(sizes, c_results['Quick Sort'])

    plt.plot(sizes, java_results['Counting Sort'])
    plt.plot(sizes, java_results['Heap Sort'])
    # plt.plot(sizes, java_results['Insertion Sort'])
    plt.plot(sizes, java_results['Merge Sort'])
    plt.plot(sizes, java_results['Quick Sort'])
    # plt.plot(sizes, c_results['Selection Sort'])
    plt.plot(sizes, python_results['Python Sort'])
    plt.xlabel('size')
    plt.ylabel('time')
    plt.legend(['C-Counting', 'C-Heap', 'C-Merge', 'C-Quick',
                'Java-Counting', 'Java-Heap', 'Java-Merge', 'Java-Quick', 'Python Sort'])
    plt.show()
    plt.savefig('./results/img/c-vs-java-performance.png')
    plt.close()
    plt.clf()

    # python vs java vs c++
    # plt.plot(sizes, c_results['Bubble Sort'])
    plt.plot(sizes, c_results['Counting Sort'])
    plt.plot(sizes, c_results['Heap Sort'])
    # plt.plot(sizes, c_results['Insertion Sort'])
    plt.plot(sizes, c_results['Merge Sort'])
    plt.plot(sizes, c_results['Quick Sort'])

    plt.plot(sizes, java_results['Counting Sort'])
    plt.plot(sizes, java_results['Heap Sort'])
    # plt.plot(sizes, java_results['Insertion Sort'])
    plt.plot(sizes, java_results['Merge Sort'])
    plt.plot(sizes, java_results['Quick Sort'])
    # plt.plot(sizes, c_results['Selection Sort'])
    plt.plot(sizes, python_results['Python Sort'])
    plt.plot(sizes, python_results['Counting Sort'])
    plt.plot(sizes, python_results['Heap Sort'])
    # plt.plot(sizes, python_results['Insertion Sort'])
    plt.plot(sizes, python_results['Merge Sort'])
    plt.plot(sizes, python_results['Quick Sort'])
    plt.xlabel('size')
    plt.ylabel('time')
    plt.legend(['C-Counting', 'C-Heap', 'C-Merge', 'C-Quick',
                'Java-Counting', 'Java-Heap', 'Java-Merge', 'Java-Quick', 'Py-Sort', 'Py-Counting', 'Py-Heap', 'Py-Merge', 'Py-Quick'])
    plt.show()
    plt.savefig('./results/img/c-java-python-performance.png')
    plt.close()
    plt.clf()

    # fast sorts
    plt.plot(sizes, c_results['Counting Sort'])
    plt.plot(sizes, c_results['Merge Sort'])
    plt.plot(sizes, c_results['Quick Sort'])

    plt.plot(sizes, java_results['Counting Sort'])
    plt.plot(sizes, java_results['Merge Sort'])
    plt.plot(sizes, java_results['Quick Sort'])

    plt.plot(sizes, python_results['Python Sort'])
    plt.xlabel('size')
    plt.ylabel('time')
    plt.legend(['C-Counting', 'C-Merge', 'C-Quick',
                'Java-Counting', 'Java-Merge', 'Java-Quick', 'Py-Sort'])
    plt.show()
    plt.savefig('./results/img/fast-performance.png')
    plt.close()
    plt.clf()
