class Solution {
public:
  int bitwiseComplement(int N) {
    if (N == 0) {
      return 1;
    }
    bitset<32> b(N);
    bool flip = false;
    for (int i = 31; i >= 0; --i) {
      if (!flip && b[i]) {
        flip = true;
      }
      if (flip) {
        b.flip(i);
      }
    }
    return b.to_ulong();
  }
};
