class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return std::max(nums[0], nums[1]);

        std::vector<int> dp(n, 0);
        dp[n-1] = nums[n-1];
        dp[n-2] = std::max(nums[n-1], nums[n-2]);

        for(int i = n - 3; i >= 0; i--){
            dp[i] = std::max(dp[i + 2] + nums[i], dp[i + 1]);
        }

        return dp[0];
    }
};
