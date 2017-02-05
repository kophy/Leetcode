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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> start2idx;
        for (int i = 0; i < intervals.size(); ++i)
            start2idx[intervals[i].start] = i;
        vector<int> result(intervals.size(), -1);
        for (int i = 0; i < intervals.size(); ++i) {
            auto iter = start2idx.lower_bound(intervals[i].end);
            if (iter != start2idx.end())
                result[i] = iter->second;
        }
        return result;
    }
};