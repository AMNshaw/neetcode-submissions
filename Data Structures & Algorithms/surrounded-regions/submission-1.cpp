class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 1) return;
        int m = board[0].size();
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        queue<vector<int>> q;
        for(int i=0; i < n; ++i){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = '#';
            }
        }
        for(int i=0; i < n; ++i){
            if(board[i][m-1] == 'O'){
                q.push({i, m-1});
                board[i][m-1] = '#';
            }
        }
        for(int i=0; i < m; ++i){
            if(board[0][i] == 'O'){
                q.push({0, i});
                board[0][i] = '#';
            }
        }
        for(int i=0; i < m; ++i){
            if(board[n-1][i] == 'O'){
                q.push({n-1, i});
                board[n-1][i] = '#';
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto& dir : dirs){
                int next_r = curr[0] + dir[0];
                int next_c = curr[1] + dir[1];
                if(next_r >=0 && next_r < n &&
                    next_c >=0 && next_c < m &&
                    board[next_r][next_c] != '#' &&
                    board[next_r][next_c] == 'O'){
                    
                    q.push({next_r, next_c});
                    board[next_r][next_c] = '#';
                }
            }
        }

        for(int i=0; i < n; ++i){
            for(int j=0; j < m; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
