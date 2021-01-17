class Solution {
 public:
  int minimumHammingDistance(vector<int>& source, vector<int>& target,
                             vector<vector<int>>& allowedSwaps) {
    vector<int> labels(source.size());
    for (int i = 0; i < labels.size(); ++i) {
      labels[i] = i;
    }
    for (const auto& as : allowedSwaps) {
      unionLabels(labels, as[0], as[1]);
    }

    unordered_map<int, unordered_set<int>> group_to_indices;
    for (int i = 0; i < labels.size(); ++i) {
      group_to_indices[findLabel(labels, i)].insert(i);
    }

    int result = 0;
    for (const auto& [_, indices] : group_to_indices) {
      unordered_map<int, int> elements;
      for (int index : indices) {
        ++elements[source[index]];
      }
      for (int index : indices) {
        if (!elements.count(target[index])) {
          continue;
        }
        if (--elements[target[index]] == 0) {
          elements.erase(target[index]);
        }
      }

      for (const auto& p : elements) {
        result += p.second;
      }
    }
    return result;
  }

 private:
  int findLabel(vector<int>& labels, int i) {
    if (labels[i] != i) {
      labels[i] = findLabel(labels, labels[i]);
    }
    return labels[i];
  }

  void unionLabels(vector<int>& labels, int i, int j) {
    labels[findLabel(labels, i)] = findLabel(labels, j);
  }
};