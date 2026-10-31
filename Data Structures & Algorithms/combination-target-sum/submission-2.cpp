class Solution {
public:
    vector<int> decision;
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        decision = nums;
        vector<int> path;
        dfs(0, 0, target, path);

        return result;
    }

    void dfs(int start, int curr, int target, vector<int>& path){
        if(curr == target){
            result.push_back(path);
            return;
        }
        if(curr > target) return;
        // The decision before has considered "all" the posibility combination, 
        // thus we don't have to count in the elements that were done before 
        for(int i = start; i<decision.size(); i++){
            path.push_back(decision[i]);
            dfs(i, curr + decision[i], target, path);
            path.pop_back();
        } 
    }
};
