from typing import List

from test_framework import generic_test


def search_first_of_k(A: List[int], k: int) -> int:

    lo, hi = 0, len(A) - 1
    # write the binary search algorithm
    # with extra condition that mid has to be lo

    while lo <= hi:
        mid = lo + (hi - lo) // 2

        if A[mid] == k:
            if lo == mid or A[mid - 1] != k:
                return mid
            hi = mid
        elif A[mid] > k:
            hi = mid - 1
        else:
            lo = mid + 1

    return -1


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('search_first_key.py',
                                       'search_first_key.tsv',
                                       search_first_of_k))
