
import random
from helper import is_sorted


class QuickSort(object):

    def sort(self, lst):
        random.shuffle(lst)
        self._sort(lst, 0, len(lst) - 1)

    def _parition(self, lst, lo, hi):
        i, j = lo + 1, hi
        # compare lo and (i, j)
        while True:

            while i < hi and lst[i] <= lst[lo]:
                i += 1

            while j > lo and lst[j] >= lst[lo]:
                j -= 1

            if i >= j:
                break

            lst[i], lst[j] = lst[j], lst[i]

        lst[lo], lst[j] = lst[j], lst[lo]

        return j

    def _sort(self, lst, lo, hi):
        if hi <= lo:
            return
        j = self._parition(lst, lo, hi)
        self._sort(lst, lo, j)
        self._sort(lst, j + 1, hi)


def main():

    list_length = 100
    list_val_range = 10000

    arr1 = [random.randrange(1, list_val_range, 1) for _ in range(list_length)]
    mg = QuickSort()
    mg.sort(arr1)

    if is_sorted(arr1):
        print("Passed")
    else:
        print("Not sorted")


if __name__ == "__main__":
    main()
