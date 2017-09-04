class Solution {
public:
	int findMinArrowShots(vector<pair<int, int>> &points) {
		if (points.size() <= 1)
			return points.size();
		sort(points.begin(), points.end(), [](pair<int, int> &p, pair<int, int> &q)->bool {
			return p.second < q.second;
		});
		int arrow = points[0].second, count = 1;
		for (int i = 1; i < points.size(); ++i) {
			if (points[i].first > arrow) {
				arrow = points[i].second;
				++count;
			}
		}
		return count;
	}
};