class Solution {
public:
  int minFlips(int a, int b, int c) {
    bitset<32> a_bits(a), b_bits(b), c_bits(c);
    return ((a_bits | b_bits) ^ c_bits).count() +
           ((a_bits & b_bits) & c_bits.flip()).count();
  }
};