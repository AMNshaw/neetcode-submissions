class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            if(__builtin_mul_overflow(res, 10, &res))
                return 0;
            if(__builtin_add_overflow(res, x%10, &res))
                return 0;
            x = x / 10;
        }
        return res;
    }
};