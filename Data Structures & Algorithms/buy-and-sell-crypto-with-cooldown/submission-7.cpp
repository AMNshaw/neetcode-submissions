class Solution {
public:
    vector<vector<int>> cache_;
    int maxProfit(vector<int>& prices) {
        cache_.assign(2, vector<int>(prices.size(), -1)); 

        return dfs(0, 1, prices);
    }

    int dfs(int i, int buying, vector<int>& prices){
        if(i >= prices.size()){
            return 0;
        }
        if(cache_[buying][i] != -1){
            return cache_[buying][i];
        }

        if(buying){
            int buy = dfs(i + 1, 0, prices) - prices[i];
            int cooldown = dfs(i + 1, 1, prices);
            cache_[buying][i] = max(buy, cooldown);
        }else{
            int sell = dfs(i+2, 1, prices) + prices[i];
            int cooldown = dfs(i+1, 0, prices);
            cache_[buying][i] = max(sell, cooldown);
        }
        return cache_[buying][i];
    }
};
