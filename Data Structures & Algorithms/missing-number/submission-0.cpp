class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int c = 0;
        for(auto nm : nums){
            c ^= nm;
        }
        for(int i =0; i < n+1; i++){
            c ^= i;
        }

        return c;
    }
};
