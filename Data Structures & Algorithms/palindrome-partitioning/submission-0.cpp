class Solution {
    std::vector<std::vector<string>> res;
public:
    vector<vector<string>> partition(string s) {

        std::vector<string> part = {};

        dfs(0, s, part);
        return res;
    }

    void dfs(int i, string& s, std::vector<string>& part){
        if(i >= s.length()){
            res.push_back(part);
            return;   
        }
        for(int j=i; j < s.size(); ++j){
            if(isPalindrom(s, i, j)){
                part.push_back(s.substr(i, j-i+1));
                dfs(j+1, s, part);
                part.pop_back();
            }

        }
    }

    bool isPalindrom(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
