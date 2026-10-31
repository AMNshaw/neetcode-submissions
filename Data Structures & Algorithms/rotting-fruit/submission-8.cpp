class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int N = grid.size();
        int N2 = grid[0].size();
        queue<pair<int, int>> currRot;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int fresh = 0;

        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[i].size(); j++)
                if(grid[i][j] == 2)
                    currRot.push({i, j});
                else if(grid[i][j] == 1)
                    fresh ++;
        
        if(!fresh) return 0;
        
        int time = 0;
        
        while(!currRot.empty()){
            int currRotNum = currRot.size();
            bool rotted = false;
            for(int i=0; i<currRotNum; i++){
                auto [r, c] = currRot.front();
                currRot.pop();
                
                for(auto &[dr, dc] : dir){
                    auto nr = r+dr;
                    auto nc = c+dc;
                    if(nr < 0 || nr >= N ||
                        nc < 0 || nc >= N2 ||
                        grid[nr][nc] != 1) continue;
                    
                    currRot.push({nr, nc});
                    grid[nr][nc] = 2;
                    fresh --;
                    rotted = true;
                }
            }
            if(rotted) time ++;
        }
        return (fresh == 0) ? time : -1;

    }
};
