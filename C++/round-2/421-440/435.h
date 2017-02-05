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
        sort(intervals.begin(), intervals.end(), [] (Interval &a, Interval &b) {
            return a.end < b.end;
        });
        int result = 0, temp = INT_MIN;
        for (auto itv : intervals) {
            // 1. overlapping, keep the interval with smaller end
            if (temp > itv.start)
                ++result;
            // 2. no overlapping, update end
            else
                temp = itv.end;
        }
        return result;
    }
};