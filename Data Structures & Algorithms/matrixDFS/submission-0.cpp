class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        rows_ = grid.size();
        cols_ = grid[0].size();
        visited_.assign(rows_, std::vector<int>(cols_, false));

        
        return dfs(0, 0, grid);
    }

    int dfs(int i, int j, vector<vector<int>>& grid){
        if (i < 0 || i >= rows_ || j < 0 || j >= cols_ || 
            grid[i][j] == 1 || visited_[i][j] == 1) {
            return 0;
        }

        if(i == rows_-1 && j == cols_-1) return 1;

        visited_[i][j] = true;

        int n = 0;
        for(auto& dir : dirs_){
            n += dfs(i + dir[0], j + dir[1], grid);
        }
        visited_[i][j] = false;

        return n;
    }

private:
    vector<vector<int>> visited_;
    int rows_ = 0;
    int cols_ = 0;
    std::vector<std::vector<int>> dirs_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
