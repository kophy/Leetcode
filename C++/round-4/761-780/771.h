class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    unordered_set<char> J_set(J.begin(), J.end());
    int result = 0;
    for (char c : S)
      if (J_set.count(c)) ++result;
    return result;
  }
};
