class Solution {
public:
    string word_;
    int n_ = 0;
    int m_ = 0;
    vector<vector<int>> dirs_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        word_ = word;
        n_ = board.size();
        m_ = board[0].size();

        for(int i=0; i< n_; ++i){
            for(int j = 0; j < m_; ++j){
                if(dfs(board, i, j, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int r, int c, int curr){
        if(board[r][c] != word_[curr]) return false;
        if(curr == word_.length() - 1) return true;

        char temp = board[r][c];
        board[r][c] = '#';

        for(const auto& dir : dirs_){
            int next_r = r + dir[0];
            int next_c = c + dir[1];
            if(next_r < n_ && next_r >=0 &&
                next_c < m_ && next_c >=0){
                if(dfs(board, next_r, next_c, curr + 1)) return true;
            }
        }

        board[r][c] = temp;
        return false;
    }
};
