class Solution {
public:
    vector<vector<int>> result_;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        dfs(0, nums, {});

        return result_;
    }

    void dfs(int i, vector<int>& nums, vector<int> prev){
        if(i == nums.size()){
            bool same = false;
            for(int j=0; j<result_.size(); ++j){
                if(prev == result_[j]) same = true;
            }
            if(!same) result_.push_back(prev);
            return;
        }

        dfs(i+1, nums, prev);
        prev.push_back(nums[i]);
        dfs(i+1, nums, prev);
    }
};
