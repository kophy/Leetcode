class Solution {
 public:
  int subarraysDivByK(vector<int>& A, int K) {
    vector<int> freq(K, 0);
    freq[0] = 1;

    int sum = 0, result = 0;
    for (int x : A) {
      sum = ((sum + x) % K + K) % K;
      result += freq[sum];
      ++freq[sum];
    }
    return result;
  }
};