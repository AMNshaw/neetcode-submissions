class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return std::max(nums[0], nums[1]);
        std::vector<int> dp(n, 0);

        dp[n-1] = nums[n-1];
        dp[n-2] = std::max(nums[n-1], nums[n-2]);

        for(int i = n-3; i >=0; i--){
            int rob = nums[i] + dp[i + 2];
            int skip = dp[i + 1];
            dp[i] = std::max(rob, skip);
        }

        return dp[0];
    }
};
