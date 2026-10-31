class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return -1;
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        std::queue<std::vector<int>> q;
        std::vector<std::vector<bool>> visit(n, std::vector<bool>(m, false)); 

        q.push({0, 0, 0});
        visit[0][0] = true;

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr[0] == n-1 && curr[1] == m-1)
                return curr[2];

            std::vector<int> next;
            int len = curr[2] + 1;
            for(const auto& dir : dirs_){
                next = {curr[0] + dir[0], curr[1] + dir[1]};
                if(next[0] < 0 || next[0] >= n ||
                    next[1] < 0 || next[1] >= m ||
                    visit[next[0]][next[1]] ||
                    grid[next[0]][next[1]] == 1){
                    continue;
                }
                visit[next[0]][next[1]] = true;
                next.push_back(len);
                q.push(next);
            }
        }

        return -1;
    }
private:
    std::vector<std::vector<int>> dirs_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

};
