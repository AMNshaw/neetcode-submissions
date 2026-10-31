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
            size_t blank = s.find("#", i);
            int num_idices = blank - i ;
            int len = stoi( s.substr(i, num_idices));
            string ss = s.substr(blank+1, len);
            result.push_back(ss);
            i = blank + 1 + len;
        }
        return result;
    }
};