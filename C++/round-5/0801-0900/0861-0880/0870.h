class Solution {
public:
  vector<int> advantageCount(vector<int> &A, vector<int> &B) {
    multiset<int> data(A.begin(), A.end());
    vector<int> result(A.size());
    vector<bool> used(result.size(), false);
    // for each element in B, try to find a larger element in A.
    for (int i = 0; i < B.size(); ++i) {
      int x = B[i];
      auto iter = data.upper_bound(x);
      if (iter != data.end()) {
        result[i] = *iter;
        used[i] = true;
        data.erase(iter);
      }
    }
    // populate rest elements in A.
    auto iter = data.begin();
    for (int i = 0; i < A.size(); ++i) {
      if (!used[i]) {
        result[i] = *iter;
        ++iter;
      }
    }
    return result;
  }
};
