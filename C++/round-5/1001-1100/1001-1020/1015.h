class Solution {
 public:
  int smallestRepunitDivByK(int K) {
    int num_mod_k = 0;
    int count = 0;
    unordered_set<int> seen;

    while (true) {
      num_mod_k = (num_mod_k * 10 + 1) % K;
      ++count;
      if (num_mod_k == 0) {
        break;
      }
      if (!seen.insert(num_mod_k).second) {
        return -1;
      }
    }
    return count;
  }
};
