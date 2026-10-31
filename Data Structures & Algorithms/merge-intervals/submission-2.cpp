class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> result;
        int mini = intervals[0][0];
        int maxi = intervals[0][1];
        for(int i=1; i < intervals.size(); ++i){
            if(maxi >= intervals[i][0]){
                maxi = max(intervals[i][1], maxi);
            }else{
                result.push_back({mini, maxi});
                mini = intervals[i][0];
                maxi = intervals[i][1];
            }
        }
        result.push_back({mini, maxi});

        return result;
    }
};
