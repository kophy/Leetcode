// A number's label will be its smallest factor greater than 1.
class Solution {
public:
  int largestComponentSize(vector<int> &A) {
    int N = *max_element(A.begin(), A.end());
    vector<int> labels(N + 1, 0);
    for (int i = 0; i < N + 1; ++i) {
      labels[i] = i;
    }
    for (int a : A) {
      for (int k = 2; k <= sqrt(a); ++k) {
        if (a % k == 0) {
          unionLabels(labels, a, k);
          unionLabels(labels, a, a / k);
        }
      }
    }
    int max_component = 0;
    unordered_map<int, int> components;
    for (int a : A) {
      int label = findLabel(labels, a);
      ++components[label];
      max_component = max(max_component, components[label]);
    }
    return max_component;
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
