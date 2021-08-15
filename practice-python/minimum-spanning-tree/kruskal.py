
from typing import List


class DisjointSet(object):

    def __init__(self, size):
        self.ids = [i for i in range(size)]

    def find(self, p):
        if self.ids[p] == p:
            return p
        self.ids[p] = self.find(self.ids[p])
        return self.ids[p]

    def union(self, p, q):
        root_p = self.find(p)
        root_q = self.find(q)
        if root_p == root_q:
            return
        self.ids[root_q] = root_p

    def connected(self, p, q):
        return self.find(p) == self.find(q)


def manhattan(p1: List[int], p2: List[int]):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])


def minCostConnectPoints(points: List[List[int]]) -> int:
    n = len(points)
    edges = []
    for i in range(n):
        for j in range(i+1, n):
            dist = manhattan(points[i], points[j])
            edges.append((dist, i, j))
    edges = sorted(edges, key=lambda x: x[0])

    # Kruskal algorithm
    res = 0
    ds = DisjointSet(n)

    for cost, u, v in edges:
        if not ds.connected(u, v):
            ds.union(u, v)
            res += cost
    return res

points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
ans = minCostConnectPoints(points)
# 20
print(ans)