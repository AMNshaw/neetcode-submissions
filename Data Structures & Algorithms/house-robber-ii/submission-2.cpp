class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return std::max(nums[0], nums[1]);
        if(n == 3) return std::max(nums[0], std::max(nums[1], nums[2]));

        std::vector<int> dp1(n, 0);
        std::vector<int> dp2(n, 0);

        dp1[n-1] = nums[n-1];
        dp1[n-2] = std::max(nums[n-1], nums[n-2]);

        for(int i = n - 3; i >= 0; i--){
            dp1[i] = std::max(nums[i] + dp1[i + 2], dp1[i + 1]);
        }

        dp2[n-2] = nums[n-2];
        dp2[n-3] = std::max(nums[n-2], nums[n-3]);

        for(int i = n - 4; i >=0; i--){
            dp2[i] = std::max(nums[i] + dp2[i + 2], dp2[i + 1]);
        }

        return std::max(dp1[1], dp2[0]);

    }
};
