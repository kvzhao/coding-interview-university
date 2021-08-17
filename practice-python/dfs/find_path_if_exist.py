
from typing import List
from collections import defaultdict

class Solution:
    def validPath(self, n: int, edges: List[List[int]], start: int, end: int) -> bool:

        graph = defaultdict(list)
        for i, j in edges:
            graph[i].append(j)
            graph[j].append(i)

        if start not in graph:
            return False

        stack = []
        visited = [False] * n
        stack.extend(graph[start])
        visited[start] = True

        while stack:
            node = stack.pop()

            if node == end:
                return True

            for neighbor in graph[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    stack.append(neighbor)

        return False


n = 10
edges = [[4,3],[1,4],[4,8],[1,7],[6,4],[4,2],[7,4],[4,0],[0,9],[5,4]]
start = 5
end = 9

solution = Solution()
ans = solution.validPath(n, edges, start, end)

if not ans:
    print("Failed")
else:
    print("Pass")