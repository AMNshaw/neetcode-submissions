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

        return self.dfs(node) if node else None

    def dfs(self, node):
        if node in self.hashMap:
            return self.hashMap[node]

        copy = Node(node.val)
        self.hashMap[node] = copy
        for nei in node.neighbors:
            copy.neighbors.append(self.dfs(nei))
        
        return copy