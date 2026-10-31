class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n-1;
        for(int i=n-2; i >= 0; --i){
            if(goal - i <= nums[i]){
                goal = i;
            }
        }
        return goal == 0;
    }
};
