class Solution {
public:
    vector<vector<int>> result_;
    vector<int> nums_;

    vector<vector<int>> subsets(vector<int>& nums) {
        nums_ = nums;
        std::sort(nums_.begin(), nums_.end());

        dfs(0, {});

        return result_;
    }

    void dfs(int i, vector<int> subset){
        if(i > nums_.size() - 1){
            result_.push_back(subset);
            return;
        }

        subset.push_back(nums_[i]);
        dfs(i+1, subset);
        subset.pop_back();
        while (i+1 < nums_.size() - 1 && nums_[i] == nums_[i+1]){
            i++;
        }
        dfs(i+1, subset);
    }
};
