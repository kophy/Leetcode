class Solution {
 public:
  int subarrayBitwiseORs(vector<int>& A) {
    unordered_set<int> result, last;
    // for each number A[i], bitwise or it with all prefixes.
    for (int i = 0; i < A.size(); ++i) {
      unordered_set<int> curr = {A[i]};
      for (int prefix : last) curr.insert(prefix | A[i]);
      result.insert(curr.begin(), curr.end());
      last = curr;
    }
    return result.size();
  }
};
