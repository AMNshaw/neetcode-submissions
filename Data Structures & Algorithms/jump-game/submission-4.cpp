class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reachable_index = nums[0];
        for(int i=1; i < nums.size(); ++i){
            if(i > max_reachable_index) return false;
            max_reachable_index = max(max_reachable_index, i + nums[i]);
        }
        return true;
    }
};
