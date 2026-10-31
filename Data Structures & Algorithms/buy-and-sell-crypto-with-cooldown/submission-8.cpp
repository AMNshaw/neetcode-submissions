class Solution {
public:
    vector<vector<int>> cache_;
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n+2, 0));

        for(int i=n-1; i >=0; --i){
            { // dp[0][i]: can buy
                int buy = dp[1][i+1] - prices[i]; 
                int skip = dp[0][i+1];
                dp[0][i] = max(buy, skip);
            }
            { // dp[1][i]: hold
                int sell = dp[0][i+2] + prices[i];
                int skip = dp[1][i+1];
                dp[1][i] = max(sell, skip);
            }
        }

        return dp[0][0];
    }
};
