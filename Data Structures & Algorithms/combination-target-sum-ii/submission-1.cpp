class Solution {
public:
    vector<vector<int>> result_;
    vector<int> candidates_;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        candidates_ = candidates;
        sort(candidates_.begin(), candidates_.end());
        vector<int> path;
        dfs(0, 0, target, path);

        return result_;
    }

    void dfs(int start, int curr, int target, vector<int>& path){
        if(curr == target){
            result_.push_back(path);
            return;
        }
        if(curr > target) return;
        
        for(int i=start; i<candidates_.size(); i++){
            if(i > start && candidates_[i] == candidates_[i-1])
                continue;

            path.push_back(candidates_[i]);
            dfs(i+1, curr + candidates_[i], target, path);
            path.pop_back();
        }
    }
};
