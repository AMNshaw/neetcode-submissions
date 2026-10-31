class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxi = nums[0];
        int mini = nums[0];
        int result = nums[0];

        for(int i=0; i < nums.size(); ++i){
            if(nums[i] == 0){
                maxi = 1;
                mini = 1;
                result = max(result, 0);
                continue;
            }
            if(i == 0) continue;

            std::vector<int> candidates = {maxi * nums[i], mini * nums[i], nums[i]};
            maxi = *std::max_element(candidates.begin(), candidates.end());
            mini = *std::min_element(candidates.begin(), candidates.end());
            result = max(result, maxi);
        }

        return result;
    }
};