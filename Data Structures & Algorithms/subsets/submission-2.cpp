class Solution {
public:
    vector<vector<int>> result_;
    vector<int> nums_;

    vector<vector<int>> subsets(vector<int>& nums) {
        nums_ = nums;
        dfs(0, {});
        return result_;
    }

    void dfs(int i, vector<int> subset){
        if(i > nums_.size() - 1){
            result_.push_back(subset);
            return;
        }

        dfs(i+1, subset);
        subset.push_back(nums_[i]);
        dfs(i+1, subset);
    }
};
