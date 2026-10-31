class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = 0

        if len(matrix) > 0:
            cols = len(matrix[0])
            
        print(f"rows: {rows} cols {cols}")

        top = 0
        bottom = rows - 1
        
        while top <= bottom:
            rowMid = (top + bottom + 1) //2
            print(f"rowMid {rowMid}")
            print(f"top {top}")
            print(f"bottom {bottom}\n")

            if matrix[rowMid][0] < target:
                top = rowMid + 1
            elif matrix[rowMid][0] > target:
                bottom = rowMid - 1
            elif matrix[rowMid][0] == target:
                return True
            if matrix[rowMid][0] < target < matrix[bottom][0]:
                break

        left = 0
        right = cols - 1

        while left <= right:
            colMid = (left + right + 1) // 2
            print(f"colMid: {colMid}")
            if matrix[rowMid][colMid] < target:
                left = colMid + 1
            elif matrix[rowMid][colMid] > target:
                right = colMid - 1
            elif matrix[rowMid][colMid] == target:
                print(True)
                return True
            
        print(False)
        return False
