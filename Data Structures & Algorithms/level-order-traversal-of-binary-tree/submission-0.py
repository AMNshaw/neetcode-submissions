# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        queue = deque()
        if root:
            queue.append(root)

        arr = []

        while len(queue) > 0:
            arrLevel = []

            for i in range(len(queue)):
                node = queue.popleft()
                arrLevel.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            arr.append(arrLevel)
        
        return arr
        