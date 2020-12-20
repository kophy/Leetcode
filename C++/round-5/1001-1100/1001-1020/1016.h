class Solution {
public:
  bool queryString(string S, int N) {
    // small optimization to avoid checking repeated patterns.
    int i = 1;
    while (i * 2 <= N) {
      i <<= 1;
    }
    i >>= 1;
    for (; i <= N; ++i) {
      if (S.find(toBinaryString(i)) == string::npos) {
        return false;
      }
    }
    return true;
  }

private:
  string toBinaryString(int N) {
    string s;
    while (N > 0) {
      s.push_back((N % 2 == 0) ? '0' : '1');
      N >>= 1;
    }
    std::reverse(s.begin(), s.end());
    return s.empty() ? "0" : s;
  }
};
