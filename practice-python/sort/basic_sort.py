
def selection_sort(lst):
    """Find the min value and swap toward"""
    length = len(lst)
    for i in range(length):
        min_index = i
        for j in range(i + 1, length):
            if lst[j] < lst[min_index]:
                min_index = j
        lst[min_index], lst[i] = lst[i], lst[min_index]


def insertion_sort(arr):
    length = len(arr)

    for i in range(1, length):
        j = i
        while j and arr[j] < arr[j - 1]:
            arr[j], arr[j - 1] = arr[j - 1], arr[j]
            j -= 1


def main():
    arr = [9, 4, 5, 1, 0, 3, 6]
    selection_sort(arr)
    print(arr)
    arr = [9, 4, 5, 1, 0, 3, 6]
    insertion_sort(arr)
    print(arr)


if __name__ == "__main__":
    main()
