class Solution {
 public:
  bool hasGroupsSizeX(vector<int> &deck) {
    unordered_map<int, int> count;
    for (int card : deck) {
      ++count[card];
    }
    int X = count.begin()->second;
    for (auto iter = count.begin(); iter != count.end(); ++iter) {
      X = gcd(X, iter->second);
    }
    return X >= 2;
  }

 private:
  int gcd(int a, int b) {
    if (a > b) {
      return gcd(b, a);
    }
    if (b % a == 0) {
      return a;
    }
    return gcd(b % a, a);
  }
};
