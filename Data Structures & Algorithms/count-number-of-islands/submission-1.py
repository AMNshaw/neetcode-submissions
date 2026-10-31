class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        self.rows = len(grid)
        self.cols = len(grid[0]) if len(grid[0]) > 0 else 0

        count = 0
        visit = set()
        
        for i in range(self.rows):
            for j in range(self.cols):
                if grid[i][j] == "1" and ((i, j) not in visit):
                    count += 1
                    self.BFS(i, j, grid, visit)
        return count

    def BFS(self, startRow, startCol, grid: List[List[str]], visit):
        
        queue = deque()
        queue.append((startRow, startCol))
        visit.add((startRow, startCol))

        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        while len(queue) > 0:
            r, c = queue.popleft()
            
            for dr, dc in directions:
                nextr = r+dr
                nextc = c+dc
                if (nextr == self.rows or nextc == self.cols or 
                min(nextr, nextc) < 0 or
                (nextr, nextc) in visit):
                    continue
                if grid[nextr][nextc] == "1":
                    queue.append((nextr, nextc))
                    visit.add((nextr, nextc)) # add next to the hashset in case that it got added to the queue again



