class Solution {
 public:
  int makeConnected(int n, vector<vector<int>> &connections) {
    if (connections.size() < n - 1) {
      return -1;
    }

    vector<int> labels(n, 0);
    for (int i = 0; i < n; ++i) {
      labels[i] = i;
    }
    for (const auto &c : connections) {
      union_labels(labels, c[0], c[1]);
    }
    unordered_set<int> unique_labels;
    for (int i = 0; i < n; ++i) {
      unique_labels.insert(find_label(labels, i));
    }
    return unique_labels.size() - 1;
  }

 private:
  int find_label(vector<int> &labels, int i) {
    if (labels[i] != i) {
      labels[i] = find_label(labels, labels[i]);
    }
    return labels[i];
  }

  void union_labels(vector<int> &labels, int i, int j) {
    labels[find_label(labels, i)] = find_label(labels, j);
  }
};