class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<std::vector<int>> bucket(nums.size() + 1);
        std::unordered_map<int, int> num_count;
        for(int i=0; i < nums.size(); i++){
            num_count[nums[i]]++;
        }

        for(auto& [n, c] : num_count){
            bucket[c].push_back(n);
        }

        std::vector<int> res;
        for(int i=bucket.size() - 1; i >= 0 && res.size() < k; i--){
            for(int n : bucket[i]){
                res.push_back(n);
                if(res.size() == k) break;
            }
        }
        return res;
    }
};
