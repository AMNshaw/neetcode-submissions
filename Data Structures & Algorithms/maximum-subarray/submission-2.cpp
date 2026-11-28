class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int cur = 0;

        for(int i = 0; i < nums.size(); i++){
            cur = std::max(cur + nums[i], nums[i]);
            res = std::max(res, cur);
        }
        return res;
    }
};
