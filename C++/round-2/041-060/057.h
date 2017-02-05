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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto iter = intervals.begin();

        /* find the first interval overlaps with newInterval */
        while (iter != intervals.end() && iter->end < newInterval.start)
            ++iter;

        /* pivot points to newInterval in intervals */
        auto pivot = intervals.insert(iter, newInterval);

        /* find the last intervals overlaps with newInterval */
        for (iter = pivot + 1; iter != intervals.end(); ++iter) {
            if (iter->start > pivot->end)
                break;
            else {
                // update newInterval
                pivot->start = min(pivot->start, iter->start);
                pivot->end = max(pivot->end, iter->end);
            }
        }

        /* remove overlapped intervals */
        intervals.erase(pivot + 1, iter);
        return intervals;
    }
};