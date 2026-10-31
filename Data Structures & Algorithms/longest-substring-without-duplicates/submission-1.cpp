class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> charSet;
        queue<char> LS;
        int maxi = 0;
        for(auto &c : s){
            while(charSet.count(c)){
                char first = LS.front();
                LS.pop();
                charSet.erase(first);
            }
            LS.push(c);
            charSet.insert(c);
            int siz = LS.size();
            maxi = max(maxi, siz);
        }
        return maxi;
    }
};
