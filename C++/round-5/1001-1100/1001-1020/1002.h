class Solution {
public:
  vector<string> commonChars(vector<string> &A) {
    if (A.empty()) {
      return {};
    }
    vector<int> common_count = getCharCount(A[0]);
    for (int i = 1; i < A.size(); ++i) {
      vector<int> v = getCharCount(A[i]);
      for (int j = 0; j < 26; ++j) {
        common_count[j] = min(common_count[j], v[j]);
      }
    }
    vector<string> result;
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < common_count[i]; ++j) {
        result.push_back(string(1, 'a' + i));
      }
    }
    return result;
  }

private:
  vector<int> getCharCount(const string &s) {
    vector<int> result(26, 0);
    for (char c : s) {
      ++result[c - 'a'];
    }
    return result;
  }
};
