class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        queue<vector<int>> pacific_queue;
        queue<vector<int>> atlantic_queue;

        std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i=0; i < n; ++i){
            pacific[i][0] = true;
            pacific_queue.push({i, 0});
        }
        for(int j=0; j<m; ++j){
            pacific[0][j] = true;
            pacific_queue.push({0, j});
        }
        for(int i=0; i < n; ++i){
            atlantic[i][m-1] = true;
            atlantic_queue.push({i, m-1});
        }
        for(int j=0; j<m; ++j){
            atlantic[n-1][j] = true;
            atlantic_queue.push({n-1, j});
        }

        while(!pacific_queue.empty()){
            auto curr = pacific_queue.front();
            pacific_queue.pop();
            for(auto& dir : dirs){
                int nr = curr[0] + dir[0], nc = curr[1] + dir[1];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !pacific[nr][nc] && heights[nr][nc] >= heights[curr[0]][curr[1]]){
                    pacific[nr][nc] = true;
                    pacific_queue.push({nr, nc});
                }
            }
        }

        while(!atlantic_queue.empty()){
            auto curr = atlantic_queue.front();
            atlantic_queue.pop();
            for(auto& dir : dirs){
                int nr = curr[0] + dir[0], nc = curr[1] + dir[1];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !atlantic[nr][nc] && heights[nr][nc] >= heights[curr[0]][curr[1]]){
                    atlantic[nr][nc] = true;
                    atlantic_queue.push({nr, nc});
                }
            }
        }

        std::vector<std::vector<int>> result;
        for(int i=0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
            }
        }

        return result;
    }
};
