class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        std::vector<int> memo(cost.size(), -1);

        return std::min(dfs(cost, 0, memo), dfs(cost, 1, memo));
    }

    int dfs(std::vector<int>& cost, int floor, std::vector<int>& memo){
        if(floor >= cost.size()) return 0;
        if(memo[floor] != -1) return memo[floor];

        memo[floor] = cost[floor] + std::min(dfs(cost, floor + 1, memo), dfs(cost, floor+2, memo));

        return memo[floor];
    }


};
