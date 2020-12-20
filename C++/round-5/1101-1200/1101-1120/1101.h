class Solution {
public:
  int earliestAcq(vector<vector<int>> &logs, int N) {
    vector<int> labels(N);
    for (int i = 0; i < N; ++i) {
      labels[i] = i;
    }
    std::sort(logs.begin(), logs.end(),
              [](const vector<int> &l1, const vector<int> &l2) -> bool {
                return l1[0] < l2[0];
              });
    for (const auto &log : logs) {
      if (findLabel(labels, log[1]) != findLabel(labels, log[2])) {
        unionLabels(labels, log[1], log[2]);
        --N;
        if (N == 1) {
          return log[0];
        }
      }
    }
    return -1;
  }

private:
  int findLabel(vector<int> &labels, int x) {
    if (labels[x] != x) {
      labels[x] = findLabel(labels, labels[x]);
    }
    return labels[x];
  }

  void unionLabels(vector<int> &labels, int x, int y) {
    labels[findLabel(labels, x)] = findLabel(labels, y);
  }
};
