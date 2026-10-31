class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp;
        mp[']'] = '[';
        mp[')'] = '(';
        mp['}'] = '{';
        
        stack<char> st;
        for(auto &ch : s){
            if(mp.find(ch) != mp.end()){
                if(st.empty() || st.top() != mp[ch])
                    return false;
                st.pop();
                continue;
            }
            st.push(ch);
        }
        return st.empty();
    }
};
