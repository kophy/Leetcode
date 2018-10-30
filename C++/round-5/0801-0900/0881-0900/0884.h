class Solution {
 public:
  vector<string> uncommonFromSentences(string A, string B) {
    unordered_map<string, int> word_to_count;
    stringstream ssa(A), ssb(B);
    string word;
    while (ssa >> word) {
      ++word_to_count[word];
    }
    while (ssb >> word) {
      ++word_to_count[word];
    }
    vector<string> result;
    for (const auto &p : word_to_count) {
      if (p.second == 1) {
        result.push_back(p.first);
      }
    }
    return result;
  }
};
