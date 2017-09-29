class Solution {
public:
    int eraseOverlapIntervals(vector<Interval> &intervals) {
        if (intervals.size() <= 1)
            return 0;
        
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b)->bool {
            return a.start < b.start;
        });
        vector<int> dp(intervals.size(), 1);
        for (int i = 1; i < intervals.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (intervals[j].end <= intervals[i].start)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return intervals.size() - *max_element(dp.begin(), dp.end());
    }
};