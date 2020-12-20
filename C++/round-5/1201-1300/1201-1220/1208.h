class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {
    int currentCost = 0;
    int left = 0, result = 0;

    for (int i = 0; i < s.size(); ++i) {
      currentCost += abs(s[i] - t[i]);
      while (left <= i && currentCost > maxCost) {
        currentCost -= abs(s[left] - t[left]);
        ++left;
      }
      result = max(result, i - left + 1);
    }
    return result;
  }
};