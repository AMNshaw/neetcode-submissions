class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(auto str : strs){
            vector<int> count(26, 0);
            for(auto ch : str){
                count[ch - 'a']++;
            }
            string key = to_string(count[0]);

            for(int i=1; i<26; i++)
                key += "," + to_string(count[i]);
            
            hash[key].push_back(str);
        }

        vector<vector<string>> result;

        for(auto group : hash)
            result.push_back(group.second);
        
        return result;
    }
};
