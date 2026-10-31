class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));

        queue<pair<int, int>> q;

        for(int i=0; i< rows; i++)
            for(int j=0; j < cols; j++)
                if(!grid[i][j]){
                    q.push({i, j});
                    visit[i][j] = true;
                }
        
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(auto [dr, dc] : dir){
                int nr = r + dr;
                int nc = c + dc;

                if(nr < 0 || nr >= rows ||
                    nc < 0 || nc >= cols ||
                    !grid[nr][nc] ||
                    grid[nr][nc] == -1 ||
                    visit[nr][nc]) continue;

                q.push({nr, nc});
                visit[nr][nc] = true;

                if(grid[nr][nc] > grid[r][c])
                    grid[nr][nc] = grid[r][c] + 1;
            }
        }
    }
};
