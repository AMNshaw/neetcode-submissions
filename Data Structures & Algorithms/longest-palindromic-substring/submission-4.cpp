class Solution {
public:
    int longest = 0;
    int longest_start = 0;

    string longestPalindrome(string s) {
        for(int i=0; i< s.size(); ++i){
            expand(i, i, s);
            expand(i, i+1, s);
        }
        return s.substr(longest_start, longest);
    }

    void expand(int left, int right, const string& s){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            int l = right - left + 1;
            if(l > longest){
                longest = l;
                longest_start = left;
            }                    
            left--;
            right++;
        }
    }
};
