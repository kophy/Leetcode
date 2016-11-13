class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int result = 0;
        for (auto &pivot : points) {
            // count the number of points with same distance to pivot
            unordered_map<int, int> count;
        for (auto &p : points)
                ++count[distp2(pivot, p)];
            for (auto iter = count.begin(); iter != count.end(); ++iter) {
                int temp  = iter->second;
                result += temp * (temp - 1);
            }
        }
        return result;
    }

private:
    int distp2(pair<int, int> &a, pair<int, int> &b) {
        return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
    }
};