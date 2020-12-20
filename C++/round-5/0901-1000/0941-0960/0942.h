class Solution {
public:
  vector<int> diStringMatch(string S) {
    int curr = 0;
    vector<int> result(S.size() + 1);
    for (int i = 0; i < S.size(); ++i) {
      if (S[i] == 'I') {
        result[i] = curr++;
      }
    }
    for (int i = S.size(); i >= 0; --i) {
      if (i == S.size() || S[i] == 'D') {
        result[i] = curr++;
      }
    }
    return result;
  }
};
