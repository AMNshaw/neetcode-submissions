#define INF INT_MAX

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m_ = grid.size();
        n_ = grid[0].size();

        std::queue<std::pair<int, int>> q;

        for(int i = 0; i < m_; i++){
            for(int j = 0; j < n_; j++){
                if(grid[i][j] != 0) continue;
                q.push({i, j});
            }
        }
    
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            for(const auto& dir : dirs_){
                int next_r = curr.first + dir[0];
                int next_c = curr.second + dir[1];

                if(next_r >= m_ || next_r < 0
                || next_c >= n_ || next_c < 0
                || grid[next_r][next_c] == -1
                || grid[next_r][next_c] != INF) continue;

                grid[next_r][next_c] = grid[curr.first][curr.second] + 1;
                q.push({next_r, next_c});
            }
        }
    }

private:
    std::vector<std::vector<int>> dirs_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m_ = 0;
    int n_ = 0;
};
