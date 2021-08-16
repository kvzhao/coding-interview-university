
import heapq
from heapq import heapify, heappop, heappush
from collections import defaultdict
from typing import List

manhattan = lambda p1, p2: abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

def minCostConnectPoints(points: List[List[int]]) -> int:
    n = len(points)
    vertices = defaultdict(list)
    for i in range(n):
        for j in range(i+1, n):
            dist = manhattan(points[i], points[j])
            vertices[i].append((dist, j))
            vertices[j].append((dist, i))

    visited = [False] * n
    heap = []
    # init
    heap.extend(vertices[0])
    visited[0] = True
    heapify(heap)

    res = 0
    count = 1
    while heap:
        cost, j = heappop(heap)

        if not visited[j]:
            visited[j] = True
            res += cost
            count += 1

            for neighbor in vertices[j]:
                heappush(heap, neighbor)

        if count >= n:
            break

    return res

points = [[0,0],[2,2],[3,10],[5,2],[7,0]]

ans = minCostConnectPoints(points)
# 20
print(ans)