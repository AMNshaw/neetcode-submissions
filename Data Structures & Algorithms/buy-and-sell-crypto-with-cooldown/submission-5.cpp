class Solution {
public:
    vector<int> prices_;
    map<pair<int, bool>, int> dp;

    int maxProfit(vector<int>& prices) {
        prices_ = prices;
        return dfs(0, true);
    }

    int dfs(int i, bool canBuy){
        if(i >= prices_.size())
            return 0;
        
        if(dp.count({i, canBuy}))
            return dp[{i, canBuy}];

        int buy, coolDown, sell;
        if(canBuy){
            buy = dfs(i+1, false) - prices_[i];
            coolDown = dfs(i + 1, true);
            dp[{i, canBuy}] = max(buy, coolDown);
        }else{
            sell = dfs(i+2, true) + prices_[i];
            coolDown = dfs(i + 1, false);
            dp[{i, canBuy}] = max(sell, coolDown);
        }
        return dp[{i, canBuy}];
        
    }


};
