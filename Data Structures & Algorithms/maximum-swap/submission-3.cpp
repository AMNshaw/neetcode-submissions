class Solution {
public:
    int maximumSwap(int num) {
        std::string n_str = std::to_string(num);
        std::vector<int> right_max(n_str.length());
        int maxi = n_str.length()-1;
        for(int i = n_str.length() - 2; i >= 0; i--){
            char c = n_str[i+1];
            if(c > n_str[maxi]){
                maxi = i+1;
            }
            right_max[i] = maxi;
        }

        for(int i=0; i < (int)n_str.length() - 1; i++){
            if(n_str[i] >= n_str[right_max[i]]){
                continue;
            }
            std::swap(n_str[i], n_str[right_max[i]]);
            return std::stoi(n_str);
        }
        return num;
    }
};
