public:
string strWithout3a3b(int A, int B) {
  int cA = 0, cB = 0;
  string result;
  while (A > 0 || B > 0) {
    if (cA == 2) {
      cA = 0;
      cB = 1;
      --B;
      result.push_back('b');
    } else if (cB == 2) {
      cA = 1;
      cB = 0;
      --A;
      result.push_back('a');
    } else if (A > B) {
      ++cA;
      cB = 0;
      --A;
      result.push_back('a');
    } else {
      cA = 0;
      ++cB;
      --B;
      result.push_back('b');
    }
  }
  return result;
}
}
;
