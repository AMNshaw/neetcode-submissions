class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        queue<pair<int, int>> positions;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        set<pair<int, int>> visit;
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && visit.find({i, j}) == visit.end()) {
                    // Start BFS
                    positions.push({i, j});
                    visit.insert({i, j});
                    while (!positions.empty()) {
                        pair<int, int> curr = positions.front();
                        positions.pop();
                        for (auto &d : directions) {
                            int newX = curr.first + d[0];
                            int newY = curr.second + d[1];
                            // Check boundaries
                            if (newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size())
                                continue;
                            // Ensure it is land and not visited
                            if (grid[newX][newY] == '1' && visit.find({newX, newY}) == visit.end()) {
                                positions.push({newX, newY});
                                visit.insert({newX, newY});
                            }
                        }
                    }
                    count++; // Increment island count
                }
            }
        }
        return count;
    }
};