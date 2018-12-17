class Solution {
 public:
  int regionsBySlashes(vector<string> &grid) {
    N = grid.size();
    vector<int> labels(N * N * 4, 0);
    for (int i = 0; i < labels.size(); ++i) {
      labels[i] = i;
    }

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        // handle 4 triangles in a square.
        if (grid[i][j] != '/') {
          unionLabels(labels, encode(i, j, 0), encode(i, j, 3));
          unionLabels(labels, encode(i, j, 1), encode(i, j, 2));
        }
        if (grid[i][j] != '\\') {
          unionLabels(labels, encode(i, j, 0), encode(i, j, 1));
          unionLabels(labels, encode(i, j, 2), encode(i, j, 3));
        }
        // handle triangles between neighboring squares.
        if (i - 1 >= 0) {
          unionLabels(labels, encode(i, j, 0), encode(i - 1, j, 2));
        }
        if (i + 1 < N) {
          unionLabels(labels, encode(i, j, 2), encode(i + 1, j, 0));
        }
        if (j - 1 >= 0) {
          unionLabels(labels, encode(i, j, 1), encode(i, j - 1, 3));
        }
        if (j + 1 < N) {
          unionLabels(labels, encode(i, j, 3), encode(i, j + 1, 1));
        }
      }
    }

    unordered_set<int> unique_labels;
    for (int i = 0; i < labels.size(); ++i) {
      unique_labels.insert(findLabel(labels, i));
    }
    return unique_labels.size();
  }

 private:
  int N;

  int encode(int i, int j, int k) { return 4 * N * i + 4 * j + k; }

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
