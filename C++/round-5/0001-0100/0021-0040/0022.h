class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    backtrack(result, "", n, 0, 0);
    return result;
  }

 private:
  void backtrack(vector<string> &result, const string &s, int n, int open,
                 int close) {
    if (open == n && close == n) {
      result.push_back(s);
      return;
    }
    if (open < n) {
      backtrack(result, s + "(", n, open + 1, close);
    }
    if (open > close) {
      backtrack(result, s + ")", n, open, close + 1);
    }
  }
};
