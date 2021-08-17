
# Definition for Employee.
from typing import List

class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates

class Solution:
    def getImportance(self, employees: List[Employee], id: int) -> int:
        # dfs
        graph = {e.id: e for e in employees}

        res = 0
        stack = []
        stack.append(graph[id])

        seen = set()
        seen.add(id)

        while stack:
            e = stack.pop()

            res += e.importance

            for sub in e.subordinates:
                if sub not in seen:
                    stack.append(graph[sub])
                    seen.add(sub)

        return res


solution = Solution()

employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]]
employees = [Employee(*e) for e in employees]

id = 1
ans = solution.getImportance(employees, id)

if ans == 11:
    print("Pass")
else:
    print("Failed")