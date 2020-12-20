class Solution {
public:
  int balancedString(string s) {
    unordered_map<char, int> expected;
    for (char c : s) {
      ++expected[c];
    }
    for (auto &p : expected) {
      p.second -= s.size() / 4;
    }

    unordered_map<char, int> window;
    if (isValid(window, expected)) {
      return 0;
    }

    int left = 0, result = s.size();
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      ++window[c];
      while (left <= i && isValid(window, expected)) {
        result = min(result, i - left + 1);
        --window[s[left]];
        ++left;
      }
    }
    return result;
  }

private:
  bool isValid(unordered_map<char, int> &window,
               unordered_map<char, int> &expected) {
    char characters[] = {'Q', 'W', 'E', 'R'};
    for (char c : characters) {
      if (window[c] < expected[c]) {
        return false;
      }
    }
    return true;
  }
};