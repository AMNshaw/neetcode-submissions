class Solution {
public:
    int total_count = 0;

    int countSubstrings(string s) {
        for(int i=0; i < s.size(); ++i){
            int j = i;
            int k = i;
            while(j >= 0 && k < s.size()){
                if(s[j] == s[k]){
                    total_count++;
                }
                else break;
                j--;
                k++;
            }
            j = i;
            k = i + 1;
            while(j >= 0 && k < s.size()){
                if(s[j] == s[k]){
                    total_count++;
                }
                else break;
                j--;
                k++;
            }
        }

        return total_count;
    }
};
