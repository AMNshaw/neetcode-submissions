class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;

        for(auto& n: nums){
            currSum = max(currSum, 0);
            currSum += n;
            maxSum = max(currSum, maxSum);
        }

        return maxSum;
    }
};
