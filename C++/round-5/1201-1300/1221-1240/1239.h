class Solution {
 public:
  int maxLength(vector<string> &arr) {
    unordered_map<string, bitset<26>> data;
    data[""] = bitset<26>(0);
    int result = 0;
    for (const string &s : arr) {
      bitset<26> mask;
      if (!getMask(s, mask)) {
        continue;
      }
      unordered_map<string, bitset<26>> next = data;
      for (const auto &p : data) {
        if ((p.second & mask).none()) {
          string t = p.first + s;
          next[t] = p.second | mask;
          result = max(result, (int)t.size());
        }
      }
      data = std::move(next);
    }
    return result;
  }

 private:
  bool getMask(const string &s, bitset<26> &mask) {
    for (char c : s) {
      if (mask.test(c - 'a')) {
        return false;
      }
      mask.set(c - 'a');
    }
    return true;
  }
};