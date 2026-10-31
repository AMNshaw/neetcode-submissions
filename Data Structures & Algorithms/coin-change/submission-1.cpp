class Solution {
public:
    std::vector<int> cache;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount+1);
        dp[0] = 0;

        for(int i=0; i<amount+1; ++i){
            for(auto& c : coins){
                if(i-c >= 0){
                    dp[i] = min(dp[i], 1 + dp[i-c]);
                }
            }
        }

        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};
