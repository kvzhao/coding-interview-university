

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
        if p == q:
            return
        root_p = self.find(p)
        root_q = self.find(q)
        if root_q == root_p:
            return
        # connect
        self.ids[root_p] = root_q

    def connected(self, p, q) -> bool:
        return self.find(p) == self.find(q)

    def num_root(self) -> int:
        return sum(index == root
            for index, root in enumerate(self.ids))


isConnected = [[1,1,0],[1,1,0],[0,0,1]]
n = len(isConnected)
uf = UnionFind(n)

for i in range(n):
    for j, connected in enumerate(isConnected[i]):
        if connected:
            uf.union(i, j)

print("number of provinces:", uf.num_root())