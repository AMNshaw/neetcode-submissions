class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        std::vector<int> curr(target.size(), 0);
        for(auto& tr : triplets){
            if(tr == target) return true;
            if(tr[0] > target[0] || tr[1] > target[1] || tr[2] > target[2]) continue;

            for(int i=0; i < target.size(); ++i){
                curr[i] = max(curr[i], tr[i]);
            }
        }
        return curr == target;
    }


};
