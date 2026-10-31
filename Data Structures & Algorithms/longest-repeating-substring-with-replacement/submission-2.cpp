class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> currTable;
        queue<char> q;
        
        int num_maxEl = 0;

        int l = 0, r = 0;
        for(int i=0; i<s.length(); i++){
            r++;
            currTable[s[i]]++;
            num_maxEl = max(num_maxEl, currTable[s[i]]);
            int len = r - l;
            if(len - num_maxEl > k){
                char popped = s[l];
                l++;

                currTable[popped]--;
                if(!currTable[popped]) currTable.erase(popped);
            }
        }
        return r - l;
    }
};
