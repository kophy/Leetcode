class Solution {
 public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int N = isConnected.size();
    vector<int> labels(N, 0);
    for (int i = 0; i < N; ++i) {
      labels[i] = i;
    }

    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        if (isConnected[i][j] == 0) {
          continue;
        }
        unionLabels(labels, i, j);
      }
    }

    unordered_set<int> unique_labels;
    for (int i = 0; i < N; ++i) {
      unique_labels.insert(findLabel(labels, i));
    }
    return unique_labels.size();
  }

 private:
  int findLabel(vector<int> &labels, int i) {
    if (labels[i] != i) {
      labels[i] = findLabel(labels, labels[i]);
    }
    return labels[i];
  }

  void unionLabels(vector<int> &labels, int i, int j) {
    labels[findLabel(labels, i)] = findLabel(labels, j);
  }
};