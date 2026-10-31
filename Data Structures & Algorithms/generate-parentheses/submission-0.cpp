class Solution {
public:
    vector<string> result_;
    int n_;
    vector<string> generateParenthesis(int n) {
        n_ = n;
        
        string tmp = "";
        dfs(n, n, tmp);

        return result_;
    }

    void dfs(int open, int close, string& path){
        
        if(open == 0 && close == 0) result_.push_back(path);

        if(open > 0){
            path += "(";
            dfs(open - 1, close, path);
            path.pop_back();
        }
        if(close > open){
            path += ")";
            dfs(open, close - 1, path);
            path.pop_back();
        }
    }
};
