class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    unordered_map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                     {'5', "jkl"}, {'6', "mno"}, {'7', "prqs"},
                                     {'8', "tuv"}, {'9', "wxyz"}};
    if (digits.size() > 0) {
      string letters(digits.size(), ' ');
      backtracking(result, m, digits, letters, 0);
    }
    return result;
  }

 private:
  void backtracking(vector<string> &result, unordered_map<char, string> &m,
                    string &digits, string &letters, int k) {
    if (k == digits.size()) {
      result.push_back(letters);
      return;
    }
    if (m.count(digits[k])) {
      for (char c : m[digits[k]]) {
        letters[k] = c;
        backtracking(result, m, digits, letters, k + 1);
      }
    }
  }
};
