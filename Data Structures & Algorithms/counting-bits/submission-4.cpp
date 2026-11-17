class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};

    
        std::vector<int> result(n+1, 0);
        int idx = 1;
        while(idx <= n){
            result[idx] = 1;
            idx = idx << 1;
        }
        if(n < 1) return result;
        int n_base = 0;
        for(int i=1; i < n + 1; i++){
            if(result[i] != 0){
                n_base = i;
                continue;
            }
            result[i] = result[n_base] + result[i - n_base];
        }

        return result;
    }
};
