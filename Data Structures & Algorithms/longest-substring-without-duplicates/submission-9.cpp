class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        std::vector<bool> char_map(128, 0);
        int left = 0;
        
        int max_len = 0;
        for(int i = 0; i < s.length(); i++){
            
            while(char_map[static_cast<unsigned char>(s[i])]) {
                char_map[static_cast<unsigned char>(s[left])] = false;
                left ++;
            }
            char_map[static_cast<unsigned char>(s[i])] = true;

            int len = i - left + 1;
            max_len = std::max(max_len, len);
        }
        return max_len;
    }
};
