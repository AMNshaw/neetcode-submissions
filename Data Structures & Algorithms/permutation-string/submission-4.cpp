class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();

        if(l1>l2){
            return false;
        }

        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for(int i=0;i<s1.length();i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        int  j = l1, i = 0;
        while(j<=l2){
            if(v1==v2){
                return true;
            } else{
                v2[s2[j]-'a']++;
                v2[s2[i]-'a']--;
                j++;
                i++;
            }
        }
        return false;
    }
};
