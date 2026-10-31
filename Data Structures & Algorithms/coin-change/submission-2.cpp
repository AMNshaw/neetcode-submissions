class Solution {
public:
    std::vector<int> cache;
    int coinChange(vector<int>& coins, int amount) {
        cache.assign(amount+1, -2);

        int res = dfs(coins, amount);


        return res >= 10001 ? -1 : res;
    }

    int dfs(vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(amount < 0) return 10001;

        if(cache[amount] != -2) return cache[amount];


        int mini = 10001;
        for(auto c : coins){
            int res = dfs(coins, amount - c);

            if(res != 10001){
                mini = min(mini, res + 1);
            }
        }

        return cache[amount] = mini;
    }
};
