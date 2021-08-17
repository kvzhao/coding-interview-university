
from typing import List
from collections import deque

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        empty = 0
        fresh = 1
        rotten = 2

        max_row = len(grid) - 1
        max_col = len(grid[0]) - 1
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        queue = deque()
        visited = set()

        num_fresh_orange = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == fresh:
                    num_fresh_orange += 1
                elif grid[i][j] == rotten:
                    queue.append((i, j))
                    visited.add((i, j))

        def get_neighbor(r, c):
            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                if not (0 <= nr <= max_row and 0 <= nc <= max_col):
                    continue
                if grid[nr][nc] == empty:
                    continue

                yield (nr, nc)

        time_elapsed = 1
        while queue:
            row, col = queue.popleft()
            if len(queue) == 0:
                time_elapsed += 1

            if grid[row][col] == fresh:
                grid[row][col] = rotten
                num_fresh_orange -= 1

            for neigobor in get_neighbor(row, col):
                if neigobor in visited:
                    continue
                queue.append(neigobor)
                visited.add(neigobor)

        return time_elapsed if num_fresh_orange == 0 else -1

sol = Solution()

grid = [[2,1,1],[1,1,0],[0,1,1]]
ans = 4
res = sol.orangesRotting(grid)
if res == ans:
    print("Pass")
else:
    print("Failed", res)
