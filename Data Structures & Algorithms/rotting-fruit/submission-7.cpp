class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> currRot;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int fresh = 0;

        // Step 1: Initialize the queue with all initially rotten oranges
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) {
                    currRot.push({i, j});
                } else if(grid[i][j] == 1) {
                    fresh++; // Count fresh oranges
                }
            }
        }

        // If there are no fresh oranges, return 0 immediately
        if (fresh == 0) return 0;

        int time = 0;

        // Step 2: BFS traversal
        while (!currRot.empty()) {
            int currRotNum = currRot.size();
            bool rotted = false; // Track if any oranges rot this round

            for (int i = 0; i < currRotNum; i++) {
                auto [r, c] = currRot.front();
                currRot.pop();

                for (auto &[dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] != 1)
                        continue;

                    // Rot the fresh orange
                    currRot.push({nr, nc});
                    grid[nr][nc] = 2;
                    fresh--;
                    rotted = true;
                }
            }
            if (rotted) time++; // Only increment time if some oranges rotted
        }

        // Step 3: If fresh oranges remain, return -1
        return (fresh == 0) ? time : -1;
    }
};