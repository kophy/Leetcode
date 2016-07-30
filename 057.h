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
        while (iter != intervals.end() && iter->end < newInterval.start)
            ++iter;
        if (iter == intervals.end()) {
            intervals.insert(iter, newInterval);
        } else {
            auto temp = intervals.insert(iter, newInterval);
            while (temp + 1 != intervals.end() && temp->end >= (temp + 1)->start) {
                *(temp + 1) = mergeInterval(*temp, *(temp + 1));
                temp = intervals.erase(temp);
            }
        }
        return intervals;
    }
private:
    Interval mergeInterval(Interval &a, Interval &b) {
        return Interval(min(a.start, b.start), max(a.end, b.end));
    }
};