class Solution {
public:
    int change(int amount, vector<int>& coins) {

        std::vector<std::vector<int>> dp(coins.size(), std::vector<int>(amount + 1, 0));
        for(int i=0; i < coins.size(); ++i){
            dp[i][0] = 1;
        }

        for(int i=0; i < coins.size(); ++i){
            for(int j=1; j <= amount; j++){
                int remain = j - coins[i];
                if(remain >= 0){
                    dp[i][j] += dp[i][remain];
                }
                if(i > 0){
                    dp[i][j] += dp[i-1][j];
                }
            }
        }
        return dp[coins.size()-1][amount];
    }
};
