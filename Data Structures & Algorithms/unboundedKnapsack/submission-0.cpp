class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int n = profit.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(capacity + 1, 0));

        for(int i=0; i<= capacity; ++i){
            if(i >= weight[0]){
                dp[0][i] = (i / weight[0]) * profit[0];
            }
        }

        for(int i=1; i< n; ++i){
            for(int j=1; j<=capacity; ++j){
                int skip = dp[i-1][j];
                int pick = 0;
                if(j - weight[i] >= 0){
                    pick = profit[i] + dp[i][j- weight[i]];
                }
                dp[i][j] = max(skip, pick);
            }
        }
        return dp[n-1][capacity];
    }
};
