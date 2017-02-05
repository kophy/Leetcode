class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if (points.size() <= 2)
            return 0;
        int N = points.size();
        vector<vector<int>> distance(N, vector<int>(N, 0));
        for (int i = 0; i < points.size(); ++i)
            for (int j = i + 1; j < points.size(); ++j)
                distance[i][j] = distance[j][i] = getSquareDistance(points[i], points[j]);
        int result = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> dist2count;
            for (int j = 0; j < points.size(); ++j)
                ++dist2count[distance[i][j]];

            for (auto iter = dist2count.begin(); iter != dist2count.end(); ++iter) {
                int count = iter->second;
                result += count * (count - 1);
            }
        }
        return result;
    }

private:
    int getSquareDistance(pair<int, int> &a, pair<int, int> &b) {
        return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
    }
};