class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return helper(0, nums);
    }

    std::vector<std::vector<int>> helper(int i, vector<int>& nums){
        if(i == nums.size()){
            return {{}};
        }
        std::vector<std::vector<int>> res_perms;
        auto perms = helper(i+1, nums);

        for(const std::vector<int>& p : perms){
            for(int j = 0; j < p.size()+1; ++j){
                std::vector<int> p_copy = p;
                p_copy.insert(p_copy.begin() + j, nums[i]);
                res_perms.push_back(p_copy);
            }
        }

        return res_perms;
    }
};
