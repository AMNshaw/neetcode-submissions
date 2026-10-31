class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        // 可選：如果需要去除重複結果，可以先排序
        // sort(nums.begin(), nums.end());
        dfs(nums, target, 0, path, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, int target, int start, vector<int>& path, int currSum) {
        if (currSum == target) {
            res.push_back(path);
            return;
        }
        if (currSum > target) {
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            // 由於同一個數字可重複使用，這裡傳入 i 而非 i+1
            dfs(nums, target, i, path, currSum + nums[i]);
            path.pop_back();
        }
    }
};
