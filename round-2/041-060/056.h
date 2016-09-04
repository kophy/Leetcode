/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b)->bool {
            return a.start < b.start;
        });
        vector<Interval> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            /*  not overlapped */
            if (result.back().end < intervals[i].start)
                result.push_back(intervals[i]);
            /*  overlapped
            	use max(result.back().end, intervals[i].end), not intervals[i].end
            	no guarantee intervals[i].end is larger
            */
            else
                result.back().end = max(result.back().end, intervals[i].end);
        }

        return result;
    }
};