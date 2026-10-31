class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> mp;

        int max_len = 0;

        for(const auto& n : nums){
            if(mp.count(n))
                continue;

            int left = 0;
            int right = 0;

            if(mp.count(n+1)){
                right = mp[n+1];
            }
            if(mp.count(n-1)){
                left = mp[n-1];
            }
            int len = left + right + 1;
            mp[n] = len;
            mp[n - left] = len;
            mp[n + right] = len;
            max_len = std::max(max_len, len);
        }

        return max_len;
    }
};
