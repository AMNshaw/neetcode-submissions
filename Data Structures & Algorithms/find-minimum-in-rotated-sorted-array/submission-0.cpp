class Solution {
public:
    int findMin(vector<int> &nums) {
        int i=0;
        int j = nums.size()-1;
        while(i  < j){
            int m = (i+j)/2;
            if(nums[m] >= nums[i] && nums[m] >= nums[j]){
                i = m+1;
            }else if(nums[m] <= nums[i] && nums[m] <= nums[j]){
                j = m;
            }else{
                return nums[i];
            }
        }
        return nums[i];
    }
};
