class Solution {
 public:
  int countComponents(int n, vector<vector<int>> &edges) {
    vector<int> labels(n);
    for (int i = 0; i < n; ++i) {
      labels[i] = i;
    }
    for (const auto &e : edges) {
      unionLabels(labels, e[0], e[1]);
    }

    unordered_set<int> unique_labels;
    for (int i = 0; i < n; ++i) {
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