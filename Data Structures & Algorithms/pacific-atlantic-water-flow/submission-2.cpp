class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        std::vector<std::vector<int>> pacific(m, std::vector<int>(n, 0));
        std::vector<std::vector<int>> atlantic(m, std::vector<int>(n, 0));

        std::queue<std::pair<int, int>> q_pa;
        std::queue<std::pair<int, int>> q_at;

        for(int i = 0; i < m; i++){
            pacific[i][0] = 1;
            q_pa.push({i, 0});
            atlantic[i][n-1] = 1;
            q_at.push({i, n-1});
        }
        for(int j = 0; j < n; j++){
            if(!pacific[0][j]){
                pacific[0][j] = 1;
                q_pa.push({0, j});
            }
            if(!atlantic[m-1][j]){
                atlantic[m-1][j] = 1;
                q_at.push({m-1, j});
            }            
        }

        bfs(pacific, heights, q_pa);
        bfs(atlantic, heights, q_at);

        std::vector<std::vector<int>> res;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
            }
        }
               
        return res;
    }

    void bfs(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& heights, std::queue<std::pair<int, int>>& q){
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            for(auto& dir : dirs_){
                int next_r = curr.first + dir[0];
                int next_c = curr.second + dir[1];

                if(next_r < 0 || next_r >= m
                || next_c < 0 || next_c >= n) continue;

                if(heights[next_r][next_c] >= heights[curr.first][curr.second]
                && grid[next_r][next_c] == 0){
                    q.push({next_r, next_c});
                    grid[next_r][next_c] = 1;
                }
            }
        }
    }

private:
    int m;
    int n;
    std::vector<std::vector<int>> dirs_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

};
