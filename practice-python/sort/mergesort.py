
import random
from typing import List


class MergeSort(object):

    def __init__(self):
        self.CUTOFF = 10

    def merge(self, aux, lst, lo, mid, hi):
        """
            Challenge 1: aux[] ~ 1/2 N
            Challenge 2: inplace merge
        """
        left, right = lo, mid + 1

        for j in range(lo, hi + 1):
            if left > mid:
                lst[j] = aux[right]
                right += 1
            elif right > hi:
                lst[j] = aux[left]
                left += 1
            elif aux[left] < aux[right]:
                lst[j] = aux[left]
                left += 1
            else:
                lst[j] = aux[right]
                right += 1

    def insertion_sort(self, lst, lo, hi):
        for i in range(lo + 1, hi + 1):
            j = i
            while j > lo and lst[j] < lst[j - 1]:
                lst[j], lst[j - 1] = lst[j - 1], lst[j]
                j -= 1

    def sort(self, lst):
        # duplicate
        aux = lst[:]
        self._sort(aux, lst, 0, len(lst) - 1)

    def _sort(self, aux, lst, lo, hi):
        if hi <= lo + self.CUTOFF - 1:
            self.insertion_sort(lst, lo, hi)
            return
        if hi <= lo:
            return
        mid = int((lo + hi) / 2)
        self._sort(lst, aux, lo, mid)
        self._sort(lst, aux, mid + 1, hi)
        if aux[mid] < aux[mid + 1]:
            # lst[lo:hi - lo + 1] = aux[lo:hi - lo + 1]
            return
        self.merge(aux, lst, lo, mid, hi)


class MergeSortBU(object):

    def merge(self, aux, lst, lo, mid, hi):
        left, right = lo, mid + 1

        for k in range(lo, hi + 1):
            aux[k] = lst[k]

        for j in range(lo, hi + 1):

            if left > mid:
                lst[j] = aux[right]
                right += 1
            elif right > hi:
                lst[j] = aux[left]
                left += 1
            elif aux[left] < aux[right]:
                lst[j] = aux[left]
                left += 1
            else:
                lst[j] = aux[right]
                right += 1

    def sort(self, lst):
        length = len(lst)
        aux = [None] * length
        size = 1
        while size < length:
            for i in range(0, length - size, size * 2):
                lo = i
                mid = i + size - 1
                hi = min(i + size * 2 - 1, length - 1)
                self.merge(aux, lst, lo, mid, hi)

            size *= 2


# 2.2.14 merge two sorted list
def merge_two_sorted(lst1: List, lst2: List) -> List:

    assert lst1 or lst2
    if not lst1 or not lst2:
        return lst1[:] if not lst2 else lst2[:]

    n1 = len(lst1)
    n2 = len(lst2)
    res = []

    i1, i2 = 0, 0

    for _ in range(n1 + n2):

        if i1 > len(lst1) - 1:
            res.extend(lst2[i2:])
            break
        elif i2 > len(lst2) - 1:
            res.extend(lst1[i1:])
            break
        elif lst1[i1] < lst2[i2]:
            res.append(lst1[i1])
            i1 += 1
        else:
            res.append(lst2[i2])
            i2 += 1

    assert len(res) == n1 + n2

    return res


def main():

    arr1 = [random.randrange(1, 100, 1) for _ in range(10)]
    mg = MergeSort()
    mg.sort(arr1)
    print(arr1)

    arr2 = [random.randrange(1, 100, 1) for _ in range(10)]
    mg = MergeSortBU()
    mg.sort(arr2)
    print(arr2)

    merged_arr = merge_two_sorted(arr1, arr2)
    print(merged_arr)


if __name__ == "__main__":
    main()
