class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<string>> key_map;
        std::vector<int> char_freq(26, 0);

        for(auto& str : strs){ 
            std::fill(char_freq.begin(), char_freq.end(), 0);  
            for(auto& c : str){
                char_freq[c - 'a']++;
            }
            std::string key = "";
            for(int i=0; i < char_freq.size(); i++){
                if(char_freq[i] == 0) continue;

                key += (std::to_string(i) + std::to_string(char_freq[i])) + ":";
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
