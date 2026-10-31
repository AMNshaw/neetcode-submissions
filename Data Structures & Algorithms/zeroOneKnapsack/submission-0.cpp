class Solution {


public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        int n = profit.size();

        std::vector<std::vector<int>> dp_array(n, std::vector<int>(capacity + 1, 0));

        for(int i=0; i<= capacity; ++i){
            if(i >= weight[0]){
                dp_array[0][i] = profit[0];
            }
        }

        for(int i=1; i< n; ++i){
            for(int j=1; j<= capacity; ++j){

                int drop = dp_array[i-1][j];
                int pick = 0;
                if(j - weight[i] >= 0){
                    pick = profit[i] + dp_array[i-1][j-weight[i]];
                }
                dp_array[i][j] = std::max(drop, pick);
            }
        }
        return dp_array[n-1][capacity];
    }



};
