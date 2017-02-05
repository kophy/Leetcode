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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.size() == 0)
            return 0;

        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) -> bool {
            return a.end < b.end || (a.end == b.end && a.start > b.start);
        });
        int pos = intervals[0].end, count = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < pos)
                ++count;
            else
                pos = max(pos, intervals[i].end);
        }
        return count;
    }
};