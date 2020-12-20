class Solution {
public:
  int repeatedNTimes(vector<int> &A) {
    unordered_set<int> unique;
    for (int x : A) {
      if (unique.count(x)) {
        return x;
      }
      unique.insert(x);
    }
    return A[0];
  }
};
