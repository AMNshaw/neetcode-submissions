class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        string longest_sub = "";
        for(int i=0; i< s.size(); ++i){
            int j = i, k = i;
            while(j >= 0 && k < s.size()){
                int l = k - j + 1;
                string sub = s.substr(j, l);
                if(is_palindrom(sub)){
                    if(l > longest){
                        longest = l;
                        longest_sub = sub;
                    }                    
                }
                j--;
                k++;
            }
        }
        for(int i=0; i< s.size(); ++i){
            int j = i, k = i+1;
            while(j >= 0 && k < s.size()){
                int l = k - j + 1;
                string sub = s.substr(j, l);
                if(is_palindrom(sub)){
                    if(l > longest){
                        longest = l;
                        longest_sub = sub;
                    }                    
                }
                j--;
                k++;
            }
        }
        return longest_sub;
    }

    bool is_palindrom(string s){
        int n = s.size();
        int i=0, j=n-1;
        while(i < j){
            if(s[i]!=s[j]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};
