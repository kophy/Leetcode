class Solution {
 public:
  int kthSmallest(vector<vector<int>> &mat, int k) {
    int M = mat.size(), N = mat[0].size();

    auto cmp = [&](const vector<int> &a, const vector<int> &b) -> bool {
      int sum_a = 0, sum_b = 0;
      for (int i = 0; i < M; ++i) {
        sum_a += mat[i][a[i]];
        sum_b += mat[i][b[i]];
      }
      return sum_a > sum_b;
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> data(cmp);
    data.push(vector<int>(M, 0));
    unordered_set<string> seen;

    vector<int> indices;
    for (int i = 0; i < k; ++i) {
      indices = data.top();
      data.pop();
      for (int j = 0; j < M; ++j) {
        if (indices[j] + 1 < N) {
          ++indices[j];
          string id = encode(indices);
          if (!seen.count(id)) {
            data.push(indices);
            seen.insert(id);
          }
          --indices[j];
        }
      }
    }

    int result = 0;
    for (int i = 0; i < M; ++i) {
      result += mat[i][indices[i]];
    }
    return result;
  }

 private:
  string encode(const vector<int> &indices) {
    stringstream ss;
    for (int x : indices) {
      ss << x << ' ';
    }
    return ss.str();
  }
};