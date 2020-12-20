class Solution {
 public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> occurrences;
    for (int x : arr) {
      ++occurrences[x];
    }

    unordered_set<int> unique_occurrences;
    for (const auto &p : occurrences) {
      if (unique_occurrences.count(p.second)) {
        return false;
      }
      unique_occurrences.insert(p.second);
    }
    return true;
  }
};