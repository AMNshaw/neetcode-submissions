class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        std::unordered_map<std::string, std::vector<std::string>> relative_dis_map;

        for(const auto& s : strings){
            char prev_c = s[0];
            std::string key = "";
            for(int i=1; i < s.length(); i++){
                char c = s[i];
                int rel = c - prev_c;
                if(rel < 0) rel += 26;
                key += (rel + 'a');
            }
            relative_dis_map[key].push_back(s);
        }
        std::vector<std::vector<std::string>> res;

        for(auto& [key, ss] : relative_dis_map){
            res.push_back(ss);
        }
        return res;
    }
};
