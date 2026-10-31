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
        std::vector<bool> check_list(26, false);
        for(int i=0; i<26;i++){
            auto range = range_vec[i];
            std::fill(check_list.begin(), check_list.end(), false);
            if(range.first == -1) continue;
            for(int i=range.first+1; i < range.second; i++){
                char c = s[i];
                int c_key = c - 'a';
                if(check_list[c_key]) continue;
                
                check_list[c_key] = true;;
                res++;
            }
        }
        return res;
    }
};