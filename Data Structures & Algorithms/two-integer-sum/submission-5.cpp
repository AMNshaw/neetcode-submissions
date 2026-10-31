class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> sub_map;

        for(int i=0; i < nums.size(); ++i){
            if(sub_map.count(nums[i])){
                return {sub_map[nums[i]], i};
            }
            int sub = target - nums[i];
            sub_map[sub] = i;
        }
    }
};
