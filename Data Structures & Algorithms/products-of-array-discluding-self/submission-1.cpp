class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        

        vector<int> result(nums.size());
        int prefix = nums[0];
        result[0] = 1;
        for(int i=1; i < nums.size(); ++i){
            result[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = nums[nums.size()-1];
        for(int i=nums.size()-2; i >=0; --i){
            result[i] *= postfix;
            postfix *= nums[i];
        }
        return result;
    }
};

