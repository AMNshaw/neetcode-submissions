class Solution {
public:
    int total_count = 0;

    int countSubstrings(string s) {
        for(int i=0; i < s.size(); ++i){
            expand(i, i, s);
            expand(i, i+1, s);
        }

        return total_count;
    }
    void expand(int i, int j, string& s){
        while(i >=0 && j <= s.length() && s[i] == s[j]){
            total_count++;
            i--;
            j++;
        }
    }

};
