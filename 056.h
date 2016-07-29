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
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b)->bool {
            return a.start < b.start;
        });
        vector<Interval> result;
        if (intervals.size())
            result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= result.back().end)
                result.back() = mergeInterval(result.back(), intervals[i]);
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
private:
    Interval mergeInterval(Interval &a, Interval &b) {
        return Interval(a.start, max(a.end, b.end));
    }
};