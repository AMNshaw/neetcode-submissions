class Solution {
public:
    bool isPalindrome(int x) {
        string n = std::to_string(x);

        int i = 0, j = n.length() - 1;

        while(i < j){
            if(n[i] != n[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};