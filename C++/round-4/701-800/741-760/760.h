class Solution {
 public:
  vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
    unordered_map<int, vector<int>> val2idx_B;
    for (int i = 0; i < B.size(); ++i) val2idx_B[B[i]].push_back(i);
    vector<int> m(A.size());
    for (int i = 0; i < A.size(); ++i) {
      m[i] = val2idx_B[A[i]].back();
      val2idx_B[A[i]].pop_back();
    }
    return m;
  }
};
