class Solution {
public:
    bool isValid(string s) {
        std::map<char, char> mp;
        std::stack<char> chs;
        
        mp.insert(std::make_pair('}', '{'));
        mp.insert(std::make_pair(')', '('));
        mp.insert(std::make_pair(']', '['));
        for(auto ch : s){
            if(mp.find(ch) != mp.end()){
                if (chs.empty() || chs.top() != mp[ch])
                    return false;
                chs.pop();
                continue;
            }
            chs.push(ch);
        }
        return chs.empty();
    }
};
