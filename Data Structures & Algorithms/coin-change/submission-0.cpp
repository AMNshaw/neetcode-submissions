class Solution {
public:
    std::vector<int> cache;
    int coinChange(vector<int>& coins, int amount) {
        cache.assign(amount + 1, -2);
        int result = dfs(coins, amount);
        return (result >= 1e9) ? -1 : result;
    }


    int dfs(vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return 1e9;

        if(cache[amount] != -2) return cache[amount];

        int min_coins = 1e9;
        for(int i=0; i< coins.size(); ++i){
            int res = dfs(coins, amount - coins[i]);

            if(res != 1e9){
                min_coins = min(min_coins, res+1);
            }
        }
        return cache[amount] = min_coins;
    }
};
