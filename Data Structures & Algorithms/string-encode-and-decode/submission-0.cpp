class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(const auto& str : strs){
            result = result + to_string(str.size()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while(i < s.size()){
            size_t found = s.find('#', i);
            int len = stoi(s.substr(i, found - i));
            string ss = s.substr(found + 1, len);
            result.push_back(ss);
            i = found + 1 + len;
        }
        return result;
    }
};