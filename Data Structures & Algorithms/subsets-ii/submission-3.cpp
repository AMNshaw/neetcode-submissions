class Solution {
public:
    vector<vector<int>> result_;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<int> init = {};
        dfs(nums, init, 0);

        return result_;
    }

    void dfs(std::vector<int>& nums, std::vector<int>& curr, int start){
        result_.push_back(curr);

        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            dfs(nums, curr, i + 1);
            curr.pop_back();
        }
    }
};
