class Solution {
public:
  int countTriplets(vector<int> &A) {
    unordered_map<int, int> pairs;
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < A.size(); ++j) {
        ++pairs[A[i] & A[j]];
      }
    }
    int result = 0;
    for (int k = 0; k < A.size(); ++k) {
      for (const auto &p : pairs) {
        if ((A[k] & p.first) == 0) {
          result += p.second;
        }
      }
    }
    return result;
  }
};
