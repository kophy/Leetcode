class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int N = s1.size();
    sort(s1.begin(), s1.end());
    for (int i = 0; i + N <= s2.size(); ++i) {
      string temp = s2.substr(i, N);
      sort(temp.begin(), temp.end());
      if (s1 == temp) {
        return true;
      }
    }
    return false;
  }
};