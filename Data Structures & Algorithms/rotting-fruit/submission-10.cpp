class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        std::queue<std::vector<int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 2) continue;

                q.push({i, j, 0});
            }
        }

        int t = 0;
        while(!q.empty()){
            auto rot = q.front();
            q.pop();
            t = rot[2];
            for(const auto& dir : dirs_){
                int next_r = rot[0] + dir[0];
                int next_c = rot[1] + dir[1];
                
                if(next_r >= m || next_r < 0
                || next_c >= n || next_c < 0
                || grid[next_r][next_c] == 0
                || grid[next_r][next_c] == 2) continue;

                q.push({next_r, next_c, rot[2] + 1});
                grid[next_r][next_c] = 2;
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return t;
    }
private:
    std::vector<std::vector<int>> dirs_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

};
