class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        std::unordered_map<int, int> count_map;

        for(int i=0; i < hand.size(); ++i){
            if(!count_map.count(hand[i])){
                pq.push(hand[i]);
            }
            count_map[hand[i]] ++;
        }

        while(!pq.empty()){
            int start = pq.top();
            if(count_map[start] == 0){
                pq.pop();
                continue;
            }

            for(int i = start; i < start + groupSize; i++){
                count_map[i]--;
                if(count_map[i] < 0){
                    return false;
                }
            }
        }

        return true;
    }
};
