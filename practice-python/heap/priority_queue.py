import random


class MaxPQ(object):
    def __init__(self, size):
        self._pq = [None] * (size + 1)
        self._size = 0

    def is_empty(self) -> bool:
        return self._size == 0

    def swim(self, k):
        # promotion
        while k > 1 and self._pq[k // 2] < self._pq[k]:
            self._pq[k // 2], self._pq[k] = self._pq[k], self._pq[k // 2]
            k //= 2

    def insert(self, val):
        self._size += 1
        self._pq[self._size] = val
        self.swim(self._size)

    def max_value(self):
        return self._pq[1]


def main():

    list_length = 10
    list_val_range = 1000
    arr = [random.randrange(1, list_val_range, 1) for _ in range(list_length)]

    max_heap = MaxPQ(size=20)

    for v in arr:
        max_heap.insert(v)

    print("arr", arr)
    print("heap max:", max_heap.max_value())
    print("max:", max(arr))


if __name__ == "__main__":
    main()
