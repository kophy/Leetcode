class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.size() <= 1)
            return points.size();
        sort(points.begin(), points.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
            return a.second < b.second;
        });
        int count = 1, pos = points[0].second;
        for (int i = 1; i < points.size(); ++i) {
            auto point = points[i];
            if (point.first > pos) {
                ++count;
                pos = point.second;
            }
        }
        return count;
    }
};