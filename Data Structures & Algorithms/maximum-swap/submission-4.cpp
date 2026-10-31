class Solution {
public:
    int maximumSwap(int num) {
        std::string n_str = std::to_string(num);
        char max_c = -1;
        int max_i = -1;
        int swap_i = -1;
        int swap_j = -1;
        
        for(int i = n_str.length()-1; i >=0; i--){
            char c = n_str[i];

            if(c > max_c){
                max_c = c;
                max_i = i;
            }
            if(c < max_c){
                swap_i = i;
                swap_j = max_i;
            }
        }
        std::swap(n_str[swap_i], n_str[swap_j]);
        return std::stoi(n_str);
    }
};
