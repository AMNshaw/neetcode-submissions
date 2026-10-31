class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        vector<vector<string>> res;

        for(auto& str : strs){
            vector<int> cnt(26, 0);
            for(auto &ch : str){
                cnt[ch - 'a']++;
            }
            string key = to_string(cnt[0]);
            for(int i=0; i<26; i++){
                key += ("," + to_string(cnt[i]));
            }
            mp[key].push_back(str);
        }

        for(auto& strs : mp){
            res.push_back(strs.second);
        }

        return res;
    }
};
