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
        vector<pair<Interval *, int>> data(intervals.size());
        for (int i = 0; i < intervals.size(); ++i)
            data[i] = make_pair(&intervals[i], i);
        sort(data.begin(), data.end(), [](pair<Interval *, int> &a, pair<Interval *, int> &b) {
            return a.first->start < b.first->start;
        });

        vector<int> result(intervals.size(), -1);
        for (int i = 0; i < data.size(); ++i) {
            for (int j = i + 1; j < data.size(); ++j) {
                if (data[j].first->start >= data[i].first->end) {
                    result[data[i].second] = data[j].second;
                    break;
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int,int> starts;
        for (int i = 0; i < intervals.size(); ++i)
            starts[intervals[i].start] = i;
        vector<int> result(intervals.size(), -1);
        for (int i = 0; i < intervals.size(); ++i) {
            // lower_bound can be used in ordered map
            auto iter = starts.lower_bound(intervals[i].end);
            if (iter != starts.end())
                result[i] = iter->second;
        }
        return result;
    }
};