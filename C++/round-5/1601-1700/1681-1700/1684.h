class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    unordered_set<char> allowed_characters(allowed.begin(), allowed.end());
    int count = 0;
    for (const string& word : words) {
      bool consistent = true;
      for (char c : word) {
        if (!allowed_characters.count(c)) {
          consistent = false;
          break;
        }
      }
      if (consistent) {
        ++count;
      }
    }
    return count;
  }
};