class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        queue<vector<int>> positions;

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int count = 0;

        for(int i=0; i< grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                
                if(grid[i][j] == '1'){
                    positions.push({i, j});
                    while(!positions.empty()){
                        vector<int> curr = positions.front();
                        positions.pop();
                        for(auto &d : directions){
                            vector<int> dir = {curr[0] + d[0], curr[1] + d[1]};
                            if(dir[0] >= grid.size() || dir[1] >= grid[0].size())
                                continue;
                            
                            if(grid[dir[0]][dir[1]] == '1'){
                                positions.push(dir);
                                grid[dir[0]][dir[1]] = '0';
                            }
                        }
                    }
                    count ++;
                }
                
            }
        }
        return count;
    }
};
