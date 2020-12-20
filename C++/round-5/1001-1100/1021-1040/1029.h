class Solution {
public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    sort(costs.begin(), costs.end(),
         [](const vector<int> &a, const vector<int> &b) -> bool {
           return (a[0] - a[1]) < (b[0] - b[1]);
         });
    int result = 0;
    int N = costs.size() / 2;
    for (int i = 0; i < costs.size(); ++i) {
      result += costs[i][i / N];
    }
    return result;
  }
};
