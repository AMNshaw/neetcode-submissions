class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_counter;
        s1_counter.reserve(s1.size());
        unordered_map<char, int> s2_counter;
        s2_counter.reserve(26);
        for(const auto& c : s1){
            s1_counter[c] ++;
        }
        int n1 = s1.size(), n2 = s2.size();
        for(int i=0; i <= (int)n2 - n1; i++) {
            unordered_map<char, int> window;
            for(int j=i; j < i + n1; j++) {
                window[s2[j]]++;
            }
            if(window == s1_counter) return true;
        }

        return false;
    }
};
