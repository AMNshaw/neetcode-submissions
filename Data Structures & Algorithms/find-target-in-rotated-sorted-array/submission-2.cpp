class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int m = 0;
        while(l <= r){
            m = (l + r) / 2;
            if(target > nums[m]){
                if(nums[m] < nums[l] && target > nums[r]){
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }else if(target < nums[m]){
                if(nums[m] > nums[r] && target < nums[l]){
                    l = m + 1;
                }else{
                    r = m - 1;
                }
            }else{
                return m;
            }
        }
        return -1;
    }
};