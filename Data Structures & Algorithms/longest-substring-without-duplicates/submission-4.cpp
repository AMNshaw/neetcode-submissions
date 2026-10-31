class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0, r = 0, maxi = 0;

        while(r < s.size()){
            if(!st.count(s[r])){
                st.insert(s[r]);
                maxi = max(r - l + 1, maxi);
                r++;
            }else{
                st.erase(s[l]);
                l++;
            }
        }
        return maxi;

    }
};
