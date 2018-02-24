class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    vector<string> result;
    backtracking(result, S, 0);
    return result;
  }

 private:
  void backtracking(vector<string> &result, string &S, int idx) {
    if (idx == S.size()) {
      result.push_back(S);
    } else {
      if (isalpha(S[idx])) {
        S[idx] = toupper(S[idx]);
        backtracking(result, S, idx + 1);
        S[idx] = tolower(S[idx]);
        backtracking(result, S, idx + 1);
      } else {
        backtracking(result, S, idx + 1);
      }
    }
  }
};
