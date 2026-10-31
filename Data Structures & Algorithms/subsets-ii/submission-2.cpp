class Solution {
public:
    vector<vector<int>> result_;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> path;
        dfs(0, nums, path);

        return result_;
    }

    void dfs(int start, vector<int>& nums, vector<int>& path){
        result_.push_back(path);

        for(int i = start; i< nums.size(); ++i){
            if(i > start && nums[i] == nums[i-1]) continue;

            path.push_back(nums[i]);
            dfs(i+1, nums, path);
            path.pop_back();
        }
    }
};
