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
    python_results = read_results('./results/csv/python-results.csv')
    print(python_results)

    # plt.plot(sizes, python_results['Bubble Sort'])
    plt.plot(sizes, python_results['Counting Sort'])
    # plt.plot(sizes, python_results['Heap Sort'])
    # plt.plot(sizes, python_results['Insertion Sort'])
    # plt.plot(sizes, python_results['Merge Sort'])
    plt.plot(sizes, python_results['Quick Sort'])
    # plt.plot(sizes, python_results['Selection Sort'])
    plt.plot(sizes, python_results['Python Sort'])
    plt.xlabel('size')
    plt.ylabel('time')
    # plt.legend([order[0], order[3], order[6]])
    # plt.legend(all_algo)
    # plt.legend(nlogn_n)
    plt.legend(['Counting Sort', 'Quick Sort', 'Python Sort'])
    plt.show()
    plt.savefig('./results/img/python-performance.png')
