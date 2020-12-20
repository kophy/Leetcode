class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int> &A) {
    vector<bool> result;
    int sum_mod_5 = 0;
    for (int x : A) {
      sum_mod_5 = (sum_mod_5 * 2 + x) % 5;
      result.push_back(sum_mod_5 == 0);
    }
    return result;
  }
};
