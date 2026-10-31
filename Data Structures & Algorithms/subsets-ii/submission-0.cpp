class Solution {
public:
    vector<unordered_map<int, int>> result_maps_; 

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result_maps_.clear();
        dfs(0, nums, {});

        vector<vector<int>> target;
        target.reserve(result_maps_.size());

        for(int i = 0; i < result_maps_.size(); ++i) {
            vector<int> values;
            for (auto const& kv : result_maps_[i]) {
                for (int j = 0; j < kv.second; ++j) {
                    values.push_back(kv.first);
                }
            }
            target.push_back(std::move(values)); 
        }

        return target;
    }

    void dfs(int i, vector<int>& nums, vector<int> prev){
        if(i == nums.size()) {
            unordered_map<int, int> count_map;
            for(int val : prev){
                count_map[val] ++;
            }
            bool same = false;
            for(int j=0; j < result_maps_.size(); ++j){
                if(result_maps_[j] == count_map) same = true;
            }
            if(!same) result_maps_.push_back(count_map);
            return;
        }

        dfs(i+1, nums, prev);
        prev.push_back(nums[i]);
        dfs(i+1, nums, prev);
    }
};
