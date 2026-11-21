/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            if(a.start != b.start){
                return a.start < b.start;
            }
            return a.end < b.end;
        });
        
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < end) return false;
            start = intervals[i].start;
            end = intervals[i].end;
        }
        return true;
    }
};
