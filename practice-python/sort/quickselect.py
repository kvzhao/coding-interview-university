
import random
from typing import List, Any


def parition(a: List, lo: int, hi: int):
    i, j = lo, hi

    v = a[lo]

    while True:
        while i < hi and a[i] <= v:
            i += 1
        while j > lo and a[j] >= v:
            j -= 1
        if i >= j:
            break
        a[i], a[j] = a[j], a[i]
    a[j], a[lo] = a[lo], a[j]

    return j


def qucik_selection(arr: List, k: int) -> Any:
    random.shuffle(arr)
    lo, hi = 0, len(arr) - 1

    while hi > lo:
        j = parition(arr, lo, hi)

        if j < k:
            lo = j + 1
        elif j > k:
            hi = j - 1
        else:
            return arr[k]

    return arr[k]


def main():
    arr = [i for i in range(100)]
    random.shuffle(arr)
    print(arr)

    for k in range(3, 10):
        print("{} th smallest {}".format(k, qucik_selection(arr, k)))


if __name__ == "__main__":
    main()
