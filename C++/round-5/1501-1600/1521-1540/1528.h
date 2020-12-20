class Solution {
public:
  string restoreString(string s, vector<int> &indices) {
    string result = s;
    for (int i = 0; i < s.size(); ++i) {
      if (i == indices[i]) {
        continue;
      }
      result[indices[i]] = s[i];
    }
    return result;
  }
};