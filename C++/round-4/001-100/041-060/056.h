class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b)->bool {
            return a.start < b.start;
        });
        vector<Interval> result;
        for (const Interval& interval : intervals) {
            if (result.empty() || result.back().end < interval.start)
                result.push_back(interval);
            else
                result.back().end = max(result.back().end, interval.end);
        }
        return result;
    }
};