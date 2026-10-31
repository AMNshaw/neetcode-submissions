class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        unordered_map<int, int> count_map;
        for(int i=0; i<hand.size(); ++i){
            if(!count_map.count(hand[i]))
                min_heap.push(hand[i]);
            count_map[hand[i]] ++;
        }

        while(!min_heap.empty()){
            int start = min_heap.top();
            if(count_map[start] == 0){
                min_heap.pop();
                continue;
            }

            for(int i=start; i < start+groupSize; ++i){
                count_map[i]--;
                if(count_map[i] < 0){
                    return false;
                }
            }
        }

        return true;
    }
};
