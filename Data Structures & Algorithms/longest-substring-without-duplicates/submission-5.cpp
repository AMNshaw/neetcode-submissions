class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, maxLength = 0;
        unordered_set<char> hs;

        for(int j=0; j<s.length(); j++){
            while(hs.count(s[j])){
                hs.erase(s[i]);
                i++;
            }
            hs.insert(s[j]);
            maxLength = max(maxLength, j-i+1);
        }
        return maxLength;
    }
};
