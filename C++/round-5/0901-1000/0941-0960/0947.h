class Solution {
public:
  int removeStones(vector<vector<int>> &stones) {
    if (stones.empty() || stones[0].empty()) {
      return 0;
    }
    int N = 0;
    for (auto &stone : stones) {
      N = max(N, stone[0] + 1);
      N = max(N, stone[1] + 1);
    }
    vector<int> indices(stones.size());
    for (int i = 0; i < stones.size(); ++i) {
      indices[i] = stones[i][0] * N + stones[i][1];
    }

    unordered_map<int, int> labels;
    for (int index : indices) {
      labels[index] = index;
    }
    for (int i = 0; i < stones.size(); ++i) {
      for (int j = i + 1; j < stones.size(); ++j) {
        if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
          unionLabels(labels, indices[i], indices[j]);
        }
      }
    }
    unordered_map<int, int> counts;
    for (int index : indices) {
      ++counts[findLabel(labels, index)];
    }
    int moves = 0;
    for (const auto &count : counts) {
      moves += count.second - 1;
    }
    return moves;
  }

private:
  void unionLabels(unordered_map<int, int> &labels, int i, int j) {
    labels[findLabel(labels, i)] = findLabel(labels, j);
  }

  int findLabel(unordered_map<int, int> &labels, int i) {
    if (labels[i] != i) {
      labels[i] = findLabel(labels, labels[i]);
    }
    return labels[i];
  }
};
