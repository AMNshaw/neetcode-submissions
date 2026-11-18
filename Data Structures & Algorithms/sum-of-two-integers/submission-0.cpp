class Solution {
public:
    int getSum(int a, int b) {
        int mask = 0xFFFFFFFF;

        while(b!=0){
            int carry = ((a & b) << 1) & mask;

            a = (a^b) & mask;
            b = carry;
        }

        return a <= 0x7FFFFFFF ? a : ~(a ^ mask);
    }
};
