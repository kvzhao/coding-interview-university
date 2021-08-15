

class UnionFind:
    def __init__(self, size):
        self.ids = [i for i in range(size)]

    def find(self, x: int) -> int:
        while x != self.ids[x]:
            # original
            # x = self.ids[x]
            # path compression - loop
            self.ids[x] = self.ids[self.ids[x]]
            x = self.ids[x]
        return x

    def union(self, p, q) -> None:
        root_p = self.find(p)
        root_q = self.find(q)

        if root_q == root_p:
            return
        # connect
        self.ids[root_p] = root_q

    def connected(self, p, q) -> bool:
        return self.find(p) == self.find(q)


uf = UnionFind(10)
# 1-2-5-6-7 3-8-9 4
uf.union(1, 2)
uf.union(2, 5)
uf.union(5, 6)
uf.union(6, 7)
uf.union(3, 8)
uf.union(8, 9)
print(uf.connected(1, 5))  # true
print(uf.connected(5, 7))  # true
print(uf.connected(4, 9))  # false
# 1-2-5-6-7 3-8-9-4
uf.union(9, 4)
print(uf.connected(4, 9))  # true