class Solution {
public:
  int maxWidthRamp(vector<int> &A) {
    vector<pair<int, int>> values_with_indices(A.size());
    for (int i = 0; i < A.size(); ++i) {
      values_with_indices[i] = make_pair(A[i], i);
    }
    sort(values_with_indices.begin(), values_with_indices.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
           if (a.first != b.first) {
             return a.first < b.first;
           }
           return a.second < b.second;
         });
    int max_width = 0, min_index = values_with_indices[0].second;
    for (const auto &p : values_with_indices) {
      if (p.second > min_index) {
        max_width = std::max(max_width, p.second - min_index);
      } else {
        min_index = p.second;
      }
    }
    return max_width;
  }
};
