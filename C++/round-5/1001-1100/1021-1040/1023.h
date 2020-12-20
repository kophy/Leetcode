class Solution {
public:
  vector<bool> camelMatch(vector<string> &queries, string pattern) {
    vector<bool> result;
    for (string &query : queries) {
      result.push_back(camelMatch(query, pattern));
    }
    return result;
  }

private:
  bool camelMatch(const string &query, const string &pattern) {
    int i = 0, j = 0;
    while (i < query.size() && j < pattern.size()) {
      if (query[i] == pattern[j]) {
        ++i;
        ++j;
      } else {
        if (isupper(query[i])) {
          return false;
        } else {
          ++i;
        }
      }
    }
    while (i < query.size() && islower(query[i])) {
      ++i;
    }
    return i == query.size() && j == pattern.size();
  }
};
