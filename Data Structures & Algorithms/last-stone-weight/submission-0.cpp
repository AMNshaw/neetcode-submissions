class Solution {
public:
    static bool compare(int a, int b){ return a < b;}
    priority_queue<int, vector<int>, decltype(&compare)> maxHeap;

    Solution() : maxHeap(&compare){}

    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];

        for(auto &stone : stones)
            maxHeap.push(stone);

        while(maxHeap.size() > 1){
            int large = maxHeap.top(); maxHeap.pop();
            int small = maxHeap.top(); maxHeap.pop();
            int crash = large - small;
            if(crash > 0)
                maxHeap.push(crash);
        }
        return maxHeap.empty()? 0 : maxHeap.top();
    }
};
