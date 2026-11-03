class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums.size() - 1;
        std::vector<std::vector<int>> result;
        for(int i=0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            l = i + 1;
            r = nums.size() - 1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum > target)
                    r--;
                else if(sum < target)
                    l++;
                else {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }
        return result;
    }
};
