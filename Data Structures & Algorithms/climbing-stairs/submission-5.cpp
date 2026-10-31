class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;

        std::vector<int> arr(2);
        arr[0] = 1;
        arr[1] = 2;
        for(int i=2; i<n; i++){
            int tmp = arr[1];
            arr[1] = arr[0] + arr[1];
            arr[0] = tmp;
        }
        return arr[1];
    }
};
