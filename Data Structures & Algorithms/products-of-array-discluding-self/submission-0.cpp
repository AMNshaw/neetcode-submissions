class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> postfix(nums.size());

        prefix[0] = nums[0];
        for(int i=1; i < nums.size(); ++i){
            prefix[i] = prefix[i-1] * nums[i];
        }

        postfix[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2; i >=0; i--){
            postfix[i] = postfix[i + 1] * nums[i];
        }

        vector<int> result(nums.size());
        result[0] = postfix[1];
        result[nums.size()-1] = prefix[nums.size()-2];
        for(int i=1; i < nums.size()-1; ++i){
            result[i] = prefix[i-1] * postfix[i+1];
        }
        return result;
    }
};

