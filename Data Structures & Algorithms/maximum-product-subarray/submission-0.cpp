class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int result = nums[0];
        int maxi = nums[0];
        int mini = nums[0];
        for(int i=0; i < nums.size(); ++i){
            if(i == 0) continue;
            if(nums[i] == 0){
                maxi = 1;
                mini = 1;
                result = max(result, 0);
                continue;
            }
            
            std::vector<int> candidate = {nums[i]*maxi, nums[i]*mini, nums[i]};
            maxi = *std::max_element(candidate.begin(), candidate.end());
            mini = *std::min_element(candidate.begin(), candidate.end());
            result = max(result, maxi);
        }
        return result;
    }
};