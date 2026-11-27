class Solution {
public:
    string longestPalindrome(string s) {
        std::string res = "";
        for(int i = 0; i < s.size(); i++){
            int l = i;
            int r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                l--;
                r++;
            }
            std::string sub1 = s.substr(l + 1, r - l - 1);

            l = i;
            r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                l--;
                r++;
            }

            std::string sub2 = s.substr(l + 1, r - l - 1);
            
            if(sub1.length() > res.length()){
                res = sub1;
            }
            if(sub2.length() > res.length()){
                res = sub2;
            }
        }

        return res;
    }
};
