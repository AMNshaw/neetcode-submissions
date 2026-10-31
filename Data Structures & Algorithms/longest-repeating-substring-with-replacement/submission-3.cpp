class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        unordered_map<char, int> char_cnt;
        int maxcnt = 0;
        int maxLength = 0;

        for(int r = 0; r < s.length(); r++){
            char_cnt[s[r]]++;
            maxcnt = max(maxcnt, char_cnt[s[r]]);
            

            while(r - l + 1 - maxcnt > k){
                char_cnt[s[l]]--;
                l++;
            }
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};
