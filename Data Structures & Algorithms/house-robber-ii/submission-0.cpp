class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];

        int rob1 = robCase(nums, 0, nums.size() - 2);
        int rob2 = robCase(nums, 1, nums.size() - 1);

        return max(rob1, rob2);
    }

    int robCase(vector<int>& nums, int s, int e){
        
        int len = e - s + 1;
        vector<int> dp(len);

        dp[0] = nums[s];
        dp[1] = max(nums[s], nums[s + 1]);

        for(int i= s + 2; i <= e; i++){
            int j = i-s;
            dp[j] = max(nums[i] + dp[j - 2], dp[j - 1]);
        }

        return dp[len-1];
    }
};
