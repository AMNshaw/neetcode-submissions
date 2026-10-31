class Solution {
public:
    int countPalindromicSubsequence(string s) {
        std::vector<std::pair<int, int>> range_vec(26, {-1, -1});

        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            int key = c - 'a';
            if(range_vec[key].first == -1){
                range_vec[key].first = i;
                range_vec[key].second = i;
            }else{
                range_vec[key].second = i;
            }
        }

        int res = 0;
        for(int i=0; i<26;i++){
            auto range = range_vec[i];
            int mask = 0;
            if(range.first == -1) continue;
            for(int j=range.first+1; j < range.second; j++){
                char c = s[j];
                int c_key = c - 'a';
                mask |= (1 << c_key);
            }
            res += __builtin_popcount(mask);
        }
        return res;
    }
};