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

        if(canBuy){
            // 选择买入或不买（直接进入下一天）
            int buy = -prices_[i] + dfs(i+1, false);
            int skip = dfs(i+1, true);
            dp[{i, canBuy}] = max(buy, skip);
        } else {
            // 已持有股票，选择卖出或继续持有
            int sell = prices_[i] + dfs(i+2, true); // 卖出后冷却一天
            int hold = dfs(i+1, false);
            dp[{i, canBuy}] = max(sell, hold);
        }
        return dp[{i, canBuy}];
    }
};