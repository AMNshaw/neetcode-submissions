class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        dfs(digits, 0, "");

        return res_;
    }

    void dfs(std::string& digits, int idx, std::string curr){
        if(idx == digits.size()) {
            res_.push_back(curr);
            return;
        }
        int d = int(digits[idx] - '0');

        for(const auto& ch : digits_char_[d]){
            dfs(digits, idx + 1, curr + ch);
        }
    }

private:
    std::vector<std::string> res_;

    std::vector<std::string> digits_char_ = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

};
