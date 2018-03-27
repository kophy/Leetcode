class Solution {
 public:
  bool rotateString(string A, string B) {
    if (A.size() != B.size()) return false;
    A += A;
    for (int i = 0; i <= B.size(); ++i) {
      if (A.substr(i, B.size()) == B) {
        return true;
      }
    }
    return false;
  }
};
