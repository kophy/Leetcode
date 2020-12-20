class Solution {
public:
  int minDominoRotations(vector<int> &A, vector<int> &B) {
    // 1. check if there is a value shared by all dominoes.
    unordered_set<int> candidates = {A[0], B[0]};
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] != A[0] && B[i] != A[0]) {
        candidates.erase(A[0]);
      }
      if (A[i] != B[0] && B[i] != B[0]) {
        candidates.erase(B[0]);
      }
    }
    if (candidates.empty()) {
      return -1;
    }
    int candidate = *candidates.begin();
    // 2. compare the cost between flipping up and down.
    int count_top = 0, count_bottom = 0;
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] != candidate) {
        ++count_top;
      }
      if (B[i] != candidate) {
        ++count_bottom;
      }
    }
    return min(count_top, count_bottom);
  }
};
