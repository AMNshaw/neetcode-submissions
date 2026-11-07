class Solution {
public:
    std::vector<std::vector<int>> res_;
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> init = {};
        dfs(nums, init, 0);

        return res_;
    }

    void dfs(std::vector<int>& nums, std::vector<int>& curr, int start){
        res_.push_back(curr);

        for(int i=start; i < nums.size(); i++){
            curr.push_back(nums[i]);
            dfs(nums, curr, i + 1);
            curr.pop_back();
        }
        return;
    }

};