
# all vertices: O(V + E)
# all paths: O(2 ** V x (V + E))

from typing import List

def allPathsSourceToTarget(graph: List[List[int]]) -> List[List[int]]:
    """ DFS
      node: 0, 1, 2, ... n-1
      Source: node: 0
      Target: mode: n-1
    """
    paths = []
    if not graph:
        return paths

    d = {}
    n = len(graph)
    for i in range(len(graph)):
        d[i] = graph[i]
    
    # Starting source
    stack = [(0, [0])]

    while stack:
        node, path = stack.pop()

        # Found the target
        if node == n - 1:
            paths.append(path)

        for neighbor in d[node]:
            stack.append((neighbor, path + [neighbor]))

    return paths

# adjacency list
graph = [[1,2],[3],[3],[]]
ans = allPathsSourceToTarget(graph)
# [[0,1,3],[0,2,3]]
print(ans)

graph = [[4,3,1],[3,2,4],[3],[4],[]]
ans = allPathsSourceToTarget(graph)
# [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
print(ans)