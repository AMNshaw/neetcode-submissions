class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        res_.reserve(std::pow(4, digits.size()));

        std::string init = {};
        dfs(digits, 0, init);

        return res_;
    }

    void dfs(std::string& digits, int idx, std::string& curr){
        if(idx == digits.size()) {
            res_.push_back(curr);
            return;
        }
        int d = int(digits[idx] - '0');

        for(int i = 0; digits_char_[d][i] != '\0'; i++){
            curr += digits_char_[d][i];
            dfs(digits, idx + 1, curr);
            curr.pop_back();
        }
    }

private:
    std::vector<std::string> res_;

    static constexpr const char* digits_char_[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

};
