class Solution {
public:
  bool isAlienSorted(vector<string> &words, string order) {
    unordered_map<char, int> m;
    for (int i = 0; i < order.size(); ++i) {
      m[order[i]] = i;
    }
    for (int i = 0; i < (int)words.size() - 1; ++i) {
      if (compare(words[i], words[i + 1], m) > 0) {
        return false;
      }
    }
    return true;
  }

private:
  int compare(string &a, string &b, unordered_map<char, int> &m) {
    if (a.size() > b.size()) {
      return -compare(b, a, m);
    }
    int i = 0;
    for (; i < min(a.size(), b.size()); ++i) {
      if (a[i] != b[i]) {
        return (m[a[i]] < m[b[i]]) ? -1 : 1;
      }
    }
    return (i < b.size()) ? -1 : 0;
  }
};
