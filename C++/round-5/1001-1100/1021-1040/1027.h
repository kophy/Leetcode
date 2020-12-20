class Solution {
public:
  int longestArithSeqLength(vector<int> &A) {
    map<int, set<int>> val_to_indices;
    for (int i = 0; i < A.size(); ++i) {
      val_to_indices[A[i]].insert(i);
    }
    int result = 0;
    for (int i = 0; i < A.size(); ++i) {
      for (int j = i + 1; j < A.size(); ++j) {
        int step = A[j] - A[i];
        int curr = j, length = 2;
        while (true) {
          int next_val = A[curr] + step;
          if (!val_to_indices.count(next_val)) {
            break;
          }
          auto iter = val_to_indices[next_val].upper_bound(curr);
          if (iter == val_to_indices[next_val].end()) {
            break;
          }
          curr = *iter;
          ++length;
        }
        result = max(result, length);
      }
    }
    return result;
  }
};
