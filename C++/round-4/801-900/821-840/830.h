class Solution {
 public:
  vector<vector<int>> largeGroupPositions(string S) {
    // simplify logic for last group.
    S.push_back('#');

    vector<vector<int>> result;
    int last = 0;
    for (int i = 0; i < S.size(); ++i) {
      if (S[i] != S[last]) {
        if (i - last >= 3) {
          result.push_back(vector<int>{last, i - 1});
        }
        last = i;
      }
    }
    return result;
  }
};
