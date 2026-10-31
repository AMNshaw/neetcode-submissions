class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> rob_first(n-1, 0);
        vector<int> rob_second(n-1, 0);
        if(n == 2) return max(nums[0], nums[1]);
        
        rob_first[0] = nums[0];
        rob_first[1] = max(nums[0], nums[1]);
        rob_second[0] = nums[1];
        rob_second[1] = max(nums[1], nums[2]);
        for(int i=2; i< n-1; ++i){
            rob_first[i] = max(rob_first[i-1], rob_first[i-2] + nums[i]);
            rob_second[i] = max(rob_second[i-1], rob_second[i-2] + nums[i+1]);
        }

        return max(rob_first[n-2], rob_second[n-2]);
    }
};
