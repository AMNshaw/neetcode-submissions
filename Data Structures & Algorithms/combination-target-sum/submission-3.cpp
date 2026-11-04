class Solution {
public:
    std::vector<std::vector<int>> result_;
    std::vector<int> nums_;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        nums_ = nums;

        std::vector<int> init = {};
        dfs(init, 0, 0, target);
        return result_;
    }

    void dfs(std::vector<int>& curr, int start, int sum, int target){
        if(sum == target) {
            result_.push_back(curr);
            return;
        }else if (sum > target) return;
        
        for(int i = start; i < nums_.size();i++){
            int n = nums_[i];
            curr.push_back(n);
            dfs(curr, i, sum + n, target);
            curr.pop_back();
        }
    }
};
