class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        self.rows = len(grid)
        self.cols = len(grid[0]) if len(grid[0]) > 0 else 0

        count = 0

        for i in range(0, self.rows):
            for j in range(0, self.cols):
                if grid[i][j] == "1":
                    count += self.DFS(grid, i, j)

        return count

    def DFS(self, grid, r, c):

        if (r == self.rows or c == self.cols or
            min(r, c) < 0 or
            grid[r][c] == "0"):
                return 0
        
        grid[r][c] = "0"

        self.DFS(grid, r+1, c)
        self.DFS(grid, r, c+1)
        self.DFS(grid, r-1, c)
        self.DFS(grid, r, c-1)
        
        return 1

