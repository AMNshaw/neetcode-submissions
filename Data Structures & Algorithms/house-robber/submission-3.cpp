class Solution {
public:

    unordered_map<int, int> mem;

    int rob(vector<int>& nums) {
        return dfs(nums, 0);
    }

    int dfs(vector<int>& nums, int i) {
        if(i >= nums.size()) return 0;

        if(mem.find(i) != mem.end()) return mem[i];
        
        int robCurrent = nums[i] + dfs(nums, i + 2);
        int skipCurrent = dfs(nums, i + 1);
        
        mem[i] = max(robCurrent, skipCurrent);

        return mem[i];
    }
};