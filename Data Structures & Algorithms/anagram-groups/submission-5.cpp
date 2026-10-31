class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<string>> key_map;

        for(auto& str : strs){ 
            std::string key(26, 0);
            for(auto& c : str){
                key[c - 'a']++;
            }
            key_map[key].push_back(str);
        }

        std::vector<std::vector<std::string>> res;
        for(auto& [k, vec] : key_map){
            res.push_back(vec);
        }

        return res;
    }
};
