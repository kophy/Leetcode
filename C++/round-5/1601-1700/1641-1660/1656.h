class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    vector<int> count1(26, 0), count2(26, 0);
    for (char c : word1) {
      ++count1[c - 'a'];
    }
    for (char c : word2) {
      // All characters in word2 must appear in word1.
      if (!count1[c - 'a']) {
        return false;
      }
      ++count2[c - 'a'];
    }
    sort(count1.begin(), count1.end());
    sort(count2.begin(), count2.end());
    return count1 == count2;
  }
};