class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int w = static_cast<int>(s1.size());
        if (w > s2.size()) return false;
        sort(s1.begin(), s1.end());
        for(int i=0; i <= (int)s2.size() - w; ++i){
            string win = s2.substr(i, w);
            sort(win.begin(), win.end());
            if (win == s1) return true;
        }
        return false;
    }
};
