class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};

    
        std::vector<int> result(n+1, 0);

        int base = 0;
        result[0] = 0;
        result[1] = 1;
        if(n < 1) return result;

        for(int i=2; i < n + 1; i++){
            int n_base = 1 << base;
            if(i == n_base << 1){
                result[i] = 1 ;
                base++;
                continue;
            }else{
                result[i] = result[n_base] + result[i - n_base];
            }
        }

        return result;
    }
};
