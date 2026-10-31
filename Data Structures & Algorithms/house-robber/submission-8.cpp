class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }
        vector<int> val(n, 0);
        val[0] = nums[0];
        val[1] = max(nums[0], nums[1]);

        for(int i=2; i < n; ++i){
            int rob = nums[i] + val[i-2];
            int pass = val[i-1];
            val[i] = max(rob, pass);
        }

        return val[n-1];
    }
};
