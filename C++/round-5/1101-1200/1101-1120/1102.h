class Solution {
 public:
  int maximumMinimumPath(vector<vector<int>> &A) {
    if (A.empty() || A[0].empty()) {
      return 0;
    }
    M = A.size();
    N = A[0].size();

    // Sort cells by value.
    vector<pair<int, int>> pos_and_val;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        pos_and_val.push_back(std::make_pair(i * N + j, A[i][j]));
      }
    }
    std::sort(pos_and_val.begin(), pos_and_val.end(),
              [](const pair<int, int> &p1, const pair<int, int> &p2) -> bool {
                return p1.second > p2.second;
              });

    vector<int> labels(M * N);
    for (int i = 0; i < labels.size(); ++i) {
      labels[i] = i;
    }

    unordered_set<int> path;
    int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

    // Add cells to the path until A[0][0] and A[M - 1][N - 1] are connected.
    for (const auto &pv : pos_and_val) {
      int i = pv.first / N, j = pv.first % N;
      for (int k = 0; k < 4; ++k) {
        int ni = i + di[k], nj = j + dj[k];
        int np = ni * N + nj;
        if (isValid(ni, nj) && path.count(np)) {
          unionLabels(labels, np, pv.first);
        }
      }
      if (findLabel(labels, 0) == findLabel(labels, M * N - 1)) {
        return pv.second;
      }
      path.insert(pv.first);
    }
    return 0;
  }

 private:
  int M, N;

  int findLabel(vector<int> &labels, int x) {
    if (labels[x] != x) {
      labels[x] = findLabel(labels, labels[x]);
    }
    return labels[x];
  }

  void unionLabels(vector<int> &labels, int x, int y) {
    labels[findLabel(labels, x)] = findLabel(labels, y);
  }

  bool isValid(int i, int j) { return i >= 0 && i < M && j >= 0 && j < N; }
};
