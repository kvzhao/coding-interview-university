

from typing import List


def is_sorted(lst: List):
    return all(lst[i] <= lst[i + 1] for i in range(len(lst) - 1))
