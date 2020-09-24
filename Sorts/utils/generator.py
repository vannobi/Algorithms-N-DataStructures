import random


def write_numbers(sizes: list):
    for cycle in range(10):
        for i in sizes:
            fwriter = open(
                './utils/random/{0}-{1}.txt'.format(i, cycle), 'w', encoding='utf-8')
            for j in range(i):
                num = random.randint(0, j)
                fwriter.write('{0}\n'.format(num))
            fwriter.close()


if __name__ == "__main__":
    f = open('./utils/number-settings.txt', 'r', encoding='utf-8')
    line_1 = int(f.readline())
    # results = [0]*line_1
    sizes = [0]*line_1
    index = 0
    for line in f:
        sizes[index] = int(line)
        index += 1
    if line_1 != len(sizes):
        print("Size given and number of examples don't match")
    else:
        print("Generating...")
        write_numbers(sizes)
        print("Done!")
    f.close()
