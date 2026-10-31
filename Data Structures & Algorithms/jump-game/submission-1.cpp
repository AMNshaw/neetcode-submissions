class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;
        for(int i=nums.size()-2; i >= 0; --i){
            if(goal - i <= nums[i]){
                goal = i;
            }
        }
        return goal == 0;
    }
};
