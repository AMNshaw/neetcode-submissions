class Solution {
public:
    vector<vector<int>> result_;
    int n_;
    int k_;

    vector<vector<int>> combine(int n, int k) {
        n_ = n;
        k_ = k;
        dfs(1, {});

        return result_;

    }

    void dfs(int i, vector<int> comb){
        if(comb.size() == k_){
            result_.push_back(comb);
            return;
        }
        if(i > n_){
            return;
        }

        comb.push_back(i);
        dfs(i + 1, comb);
        comb.pop_back();
        dfs(i+1, comb);
    }
};