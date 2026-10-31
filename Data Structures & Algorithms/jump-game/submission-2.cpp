class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_reachable_index = nums[0];
        for(int i=1; i < n; ++i){
            if(i > max_reachable_index) return false;
            max_reachable_index = max(max_reachable_index, i + nums[i]);
        }
        return true;
    }
};
