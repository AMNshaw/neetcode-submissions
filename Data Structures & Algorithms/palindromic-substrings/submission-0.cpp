class Solution {
public:
    int total_count = 0;

    int countSubstrings(string s) {
        
        for(int i=0; i < s.size(); ++i){
            int j = i;
            int k = i;
            while(j >= 0 && k < s.size()){
                string sub = s.substr(j, k-j +1);
                if(isPalindrom(sub)){
                    total_count++;
                }
                else break;
                j--;
                k++;
            }
            j = i;
            k = i + 1;
            while(j >= 0 && k < s.size()){
                string sub = s.substr(j, k-j +1);
                if(isPalindrom(sub)){
                    total_count++;
                }
                else break;
                j--;
                k++;
            }
        }

        return total_count;
    }
    

    bool isPalindrom(string s){
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

};
