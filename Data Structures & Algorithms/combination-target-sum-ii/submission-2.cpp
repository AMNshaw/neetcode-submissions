class Solution {
public:
    std::vector<std::vector<int>> result_;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> start = {};

        dfs(candidates, target, 0, 0, start);

        return result_;
    }

    void dfs(std::vector<int>& candidates, int target, int start, int sum, std::vector<int>& curr){
        if(sum == target) {
            result_.push_back(curr);
            return;
        }
        if(sum > target) return;

        for(int i = start; i < candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i - 1]) continue;
            curr.push_back(candidates[i]);
            dfs(candidates, target, i + 1, sum + candidates[i], curr);
            curr.pop_back();
        }
    }
};
