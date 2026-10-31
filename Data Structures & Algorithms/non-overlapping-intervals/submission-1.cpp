class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        int start = 0, res = 0;
        int end = intervals[0][1];
        for(int i=1; i < intervals.size(); ++i){
            start = intervals[i][0];
            if(start >= end){
                end = intervals[i][1];
            }else{
                res++;
                end = min(end, intervals[i][1]);
            }
            
        }

        return res;
    }

};
