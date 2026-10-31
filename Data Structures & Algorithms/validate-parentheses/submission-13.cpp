class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp;
        mp[']'] = '[';
        mp[')'] = '(';
        mp['}'] = '{';
        
        stack<char> st;
        for(auto &ch : s){
            if(st.empty()){
                if(mp.count(ch))
                    return false;
                st.push(ch);
                continue;
            }
            if(mp[ch] == st.top()){
                st.pop();
                continue;
            }
            st.push(ch);
        }
        return st.empty();
    }
};
