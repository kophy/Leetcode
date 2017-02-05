class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.size() <= 1)
            return points.size();
        sort(points.begin(), points.end(), [](pair<int, int> &a, pair<int, int> &b)->bool {
            return a.second < b.second;
        });
        int result = 0, temp = INT_MIN;
        for (auto &p : points) {
            if (p.first > temp) {
                ++result;
                temp = max(temp, p.second);
            }
        }
        return result;
    }
};