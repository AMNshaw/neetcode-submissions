class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> prefix_sum;
        prefix_sum[0] = 1;
        
        int total = 0;
        int res = 0;
        for(int i=0; i < nums.size(); i++){
            total += nums[i];
            auto it = prefix_sum.find(total - k);
            if(it != prefix_sum.end()){
                res += it->second;
            } 
            prefix_sum[total]++;
        }
        
        return res;
    }
};