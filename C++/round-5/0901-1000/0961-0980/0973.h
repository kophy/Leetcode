class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
    auto cmp = [](const pair<long, int> &a, const pair<long, int> &b) -> bool {
      return a.first < b.first;
    };
    std::priority_queue<pair<long, int>, std::vector<pair<long, int>>,
                        decltype(cmp)>
        k_closest_points(cmp);

    for (int i = 0; i < points.size(); ++i) {
      const auto &point = points[i];
      long distance = pow(point[0], 2) + pow(point[1], 2);
      if (k_closest_points.size() < K) {
        k_closest_points.push(std::make_pair(distance, i));
      } else if (distance < k_closest_points.top().first) {
        k_closest_points.pop();
        k_closest_points.push(std::make_pair(distance, i));
      }
    }
    vector<vector<int>> result;
    for (int i = 0; i < K; ++i) {
      int index = k_closest_points.top().second;
      k_closest_points.pop();
      result.push_back(points[index]);
    }
    return result;
  }
};