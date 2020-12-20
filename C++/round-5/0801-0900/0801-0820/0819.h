class Solution {
public:
  string mostCommonWord(string paragraph, vector<string> &banned) {
    unordered_set<string> banned_set(banned.begin(), banned.end());
    unordered_map<string, int> count;

    int i = 0;
    while (i < paragraph.size()) {
      while (i < paragraph.size() && !isalpha(paragraph[i])) {
        ++i;
      }
      if (i >= paragraph.size()) {
        break;
      }
      int len = 0;
      while (i + len < paragraph.size() && isalpha(paragraph[i + len])) {
        ++len;
      }
      string word = paragraph.substr(i, len);
      for (int j = 0; j < word.size(); ++j) {
        word[j] = tolower(word[j]);
      }

      if (!banned_set.count(word)) {
        ++count[word];
      }
      i += len;
    }

    string word;
    int max_count = 0;
    for (const auto &p : count) {
      if (max_count < p.second) {
        word = p.first;
        max_count = p.second;
      }
    }
    return word;
  }
};