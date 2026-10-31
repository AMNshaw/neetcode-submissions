class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> result(n+1, 0);

        for(int i=0; i < n+1; i++){
            result[i] = bits(i);
        }
        return result;
    }

    int bits(int num){
        int res = 0;
        while(num > 0){
            if(num & 1) res++;
            num = num >> 1;
        }
        return res;
    }
};
