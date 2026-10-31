class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> currTable;
        queue<char> q;
        
        int num_maxEl = 0;
        for(auto &ch : s){
            q.push(ch);
            currTable[ch]++;
            num_maxEl = max(num_maxEl, currTable[ch]);

            if(q.size() - num_maxEl > k){
                char popped = q.front();
                q.pop();

                currTable[popped]--;
                if(!currTable[popped]) currTable.erase(popped);
            }
        }
        return q.size();
    }
};
