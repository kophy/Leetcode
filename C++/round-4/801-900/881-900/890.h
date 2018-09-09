class Solution {
 public:
  vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
    vector<string> result;
    for (const string &word : words) {
      if (match(word, pattern)) {
        result.push_back(word);
      }
    }
    return result;
  }

 private:
  bool match(const string &word, const string &pattern) {
    if (word.size() != pattern.size()) {
      return false;
    }
    unordered_map<char, char> m;
    unordered_set<char> used;
    for (int i = 0; i < word.size(); ++i) {
      if (m.find(word[i]) != m.end()) {
        if (m[word[i]] != pattern[i]) {
          return false;
        }
      } else if (used.find(pattern[i]) != used.end()) {
        return false;
      } else {
        m[word[i]] = pattern[i];
        used.insert(pattern[i]);
      }
    }
    return true;
  }
};
