class Solution {
public:
    int countPalindromicSubsequence(string s) {
        std::unordered_map<char, std::pair<int, int>> range_map;

        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(!range_map.count(c)){
                range_map[c].first = i;
                range_map[c].second = i;
            } else{
                range_map[c].second = i;
            }
        }

        int res = 0;
        std::vector<bool> check_list(26, false);
        for(auto& [c_key, range] : range_map){
            std::fill(check_list.begin(), check_list.end(), false);
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