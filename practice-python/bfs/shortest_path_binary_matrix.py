
from typing import Deque, List
from collections import deque

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        max_row = len(grid) - 1
        max_col = len(grid[0]) - 1
        directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]

        def get_neighbor(r, c):
            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                if not (0 <= nr <= max_row and 0 <= nc <= max_col):
                    continue
                if grid[nr][nc] != 0:
                    continue

                yield (nr, nc)

        if grid[0][0] != 0 or grid[max_row][max_row] !=0:
            return -1

        queue = deque([(0, 0, 1)])
        visited = set((0, 0))

        while queue:
            row, col, dist = queue.popleft()
            if (row, col) == (max_row, max_row):
                return dist
            
            for neighbor in get_neighbor(row, col):
                if neighbor in visited:
                    continue
                visited.add(neighbor)

                queue.append((*neighbor, dist + 1))

        return -1

solution = Solution()

grid = [[0,1],[1,0]]
ans = solution.shortestPathBinaryMatrix(grid)
if ans == 2:
    print("Pass")
else:
    print("Failed")

grid = [[0,0,0],[1,1,0],[1,1,0]]
ans = solution.shortestPathBinaryMatrix(grid)
if ans == 4:
    print("Pass")
else:
    print("Failed")
