class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        
        // 當 x 小於或等於 revertedNumber 時，代表已經處理到數字的一半
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 偶數長度判斷: x == revertedNumber
        // 奇數長度判斷: x == revertedNumber / 10 (忽略中間位數)
        return x == revertedNumber || x == revertedNumber / 10;
    }
};