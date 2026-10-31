"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:

        self.hashMap = {}

        return self.bfs(node) if node else None

    def bfs(self, node):
        queue = deque()
        queue.append(node)

        copy = Node(node.val)
        self.hashMap[node] = copy
        while queue:
            for i in range(len(queue)):
                nd = queue.popleft()
                for nei in nd.neighbors:
                    if nei not in self.hashMap:
                        queue.append(nei)
                        new = Node(nei.val)
                        self.hashMap[nei] = new

                    self.hashMap[nd].neighbors.append(self.hashMap[nei])

        return copy
        
