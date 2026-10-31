class TreeNode:
    def __init__(self, key, val):

        self.key = key
        self.val = val
        self.left = None
        self.right = None

class TreeMap:
    def __init__(self):
        self.root = None

    def insert(self, key: int, val: int) -> None:
        newNode = TreeNode(key, val)

        if self.root == None:
            self.root = newNode
            return

        currNode = self.root
        while True:
            if key > currNode.key:
                if currNode.right is None:
                    currNode.right = TreeNode(key, val)
                    return
                currNode = currNode.right
            elif key < currNode.key:
                if currNode.left is None:
                    currNode.left = TreeNode(key, val)
                    return
                currNode = currNode.left
            else:
                currNode.val = val
                return


    def get(self, key: int) -> int:
        current = self.root
        while current != None:
            if key < current.key:
                current = current.left
            elif key > current.key:
                current = current.right
            else:
                return current.val
        return -1

    def findMin(self, root: TreeNode)->TreeNode:
        currNode = root
        while currNode and currNode.left:
            currNode = currNode.left
        return currNode

    def getMin(self) -> int:
        minNode = self.findMin(self.root)
        return minNode.val if minNode else -1

    def getMax(self) -> int:
        currNode = self.root
        while currNode and currNode.right:
            currNode = currNode.right
        return currNode.val if currNode else -1

    def remove(self, key: int) -> None:
        
        self.root = self.removeHelper(self.root, key)

    def removeHelper(self, node: TreeNode , key: int):
        if node == None:
            return None

        if key > node.key:
            node.right = self.removeHelper(node.right, key)
        elif key < node.key:
            node.left = self.removeHelper(node.left, key)
        else:
            if node.left == None:
                return node.right
            elif node.right == None:
                return node.left
            else:
                minNode = self.findMin(node.right)
                node.val = minNode.val
                node.key = minNode.key
                node.right = self.removeHelper(node.right, minNode.key)
        return node
        
    def getInorderKeys(self) -> List[int]:
        arr = []
        self.DFS(self.root, arr)
        return arr

    def DFS(self, node: TreeNode, arr: List[int]) -> None:

        if not node:
            return
        
        self.DFS(node.left, arr)
        arr.append(node.key)
        self.DFS(node.right, arr)





