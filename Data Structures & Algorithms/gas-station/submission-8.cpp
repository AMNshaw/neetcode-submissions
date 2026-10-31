class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int accum = 0;
        int result = 0;
        for(int i=0; i < gas.size(); ++i){
            int diff = gas[i] - cost[i];
            accum += diff;
            total += diff;
            if(total < 0){
                total = 0;
                result = -1;
            }else{
                if(result == -1)
                    result = i;
            }
        }
        return accum < 0 ? -1 : result;
    }
};
