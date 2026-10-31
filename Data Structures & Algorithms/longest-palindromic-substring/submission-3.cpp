class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        int longest_start = 0;
        for(int i=0; i< s.size(); ++i){
            int j = i, k = i;
            while(j >= 0 && k < s.size() && s[j] == s[k]){
                int l = k - j + 1;
                if(l > longest){
                    longest = l;
                    longest_start = j;
                }                    
                j--;
                k++;
            }
        }
        for(int i=0; i< s.size(); ++i){
            int j = i, k = i+1;
            while(j >= 0 && k < s.size() && s[j] == s[k]){
                int l = k - j + 1;
                if(l > longest){
                    longest = l;
                    longest_start = j;
                }                    
                j--;
                k++;
            }
        }
        return s.substr(longest_start, longest);
    }
};
