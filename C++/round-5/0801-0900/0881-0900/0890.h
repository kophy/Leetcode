class Solution {
public:
  vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
    string standard = getStandardForm(pattern);
    vector<string> result;
    for (const string &word : words) {
      if (getStandardForm(word) == standard) {
        result.push_back(word);
      }
    }
    return result;
  }

private:
  string getStandardForm(const string &s) {
    string t(s.size(), ' ');
    unordered_map<char, char> m;
    for (int i = 0; i < s.size(); ++i) {
      if (!m.count(s[i])) {
        char c = 'a' + m.size();
        m[s[i]] = c;
      }
      t[i] = m[s[i]];
    }
    return t;
  }
};
