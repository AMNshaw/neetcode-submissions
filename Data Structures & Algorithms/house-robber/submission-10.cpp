class Solution {
public:
    int rob(vector<int>& nums) {
        
        std::vector<int> memo(nums.size(), -1);

        return dfs(nums, 0, memo);
    }

    int dfs(std::vector<int>& nums, int idx, std::vector<int>& memo){
        if(idx >= nums.size()) return 0;        
        if(memo[idx] != -1) return memo[idx];

        memo[idx] = std::max(dfs(nums, idx + 1, memo), nums[idx] + dfs(nums, idx + 2, memo));

        return memo[idx];
    }


};
