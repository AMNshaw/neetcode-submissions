class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for(const auto &str : strs){
            vector<int> table(26, 0);
            for(char c : str)
                table[c - 'a']++;
            
            string key = to_string(table[0]);

            for(int i=1; i<26; i++){
                key += "," + to_string(table[i]);
            }

            res[key].push_back(str);
        }
        vector<vector<string>> out;
        for(const auto& str : res){
            out.push_back(str.second);
        }
        return out;
    }
};
