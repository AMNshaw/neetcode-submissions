class Solution {
public:
    int target_;
    std::map<pair<int, int>, int> dp_;
    int findTargetSumWays(vector<int>& nums, int target) {
        
        target_ = target;
        

        return dfs(nums, 0, 0);
    }


    int dfs(vector<int>& nums, int curr_sum, int i){
        if(dp_.count({i, curr_sum})) return dp_[{i, curr_sum}];

        if(i == nums.size()){
            if(curr_sum == target_){
                return 1;
            }else{
                return 0;
            }
        }

        return dp_[{i, curr_sum}] = dfs(nums, curr_sum + nums[i], i+1) + dfs(nums, curr_sum - nums[i], i + 1);
    }
};
