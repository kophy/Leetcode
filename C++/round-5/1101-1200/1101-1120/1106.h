class Solution {
 public:
  bool parseBoolExpr(string expression) {
    if (expression == "t") {
      return true;
    } else if (expression == "f") {
      return false;
    } else if (expression[0] == '!') {
      return !parseBoolExpr(expression.substr(2, expression.size() - 3));
    } else if (expression[0] == '|') {
      vector<string> exprs =
          splitExprs(expression.substr(2, expression.size() - 3));
      bool result = false;
      for (const string &expr : exprs) {
        result = result || parseBoolExpr(expr);
      }
      return result;
    } else {
      vector<string> exprs =
          splitExprs(expression.substr(2, expression.size() - 3));
      bool result = true;
      for (const string &expr : exprs) {
        result = result && parseBoolExpr(expr);
      }
      return result;
    }
    return false;
  }

 private:
  vector<string> splitExprs(const string &s) {
    vector<string> exprs;
    int count = 0;
    int i = 0;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == '(') {
        ++count;
      } else if (s[j] == ')') {
        --count;
      } else if (s[j] == ',') {
        if (count == 0) {
          exprs.push_back(s.substr(i, j - i));
          i = j + 1;
        }
      }
    }
    exprs.push_back(s.substr(i));
    return exprs;
  }
};
