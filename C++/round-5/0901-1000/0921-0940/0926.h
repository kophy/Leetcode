class Solution {
public:
  int minFlipsMonoIncr(string S) {
    int N = S.size();
    int total_ones = 0;
    for (int i = 0; i < N; ++i) {
      total_ones += S[i] - '0';
    }
    // count the number of 1 before S[i].
    vector<int> pre_ones(S.size(), 0);
    for (int i = 0; i < N - 1; ++i) {
      pre_ones[i + 1] = pre_ones[i] + (S[i] - '0');
    }
    // baseline is making all elements 0 or 1.
    int result = min(total_ones, N - total_ones);
    // for each i, calculate #flips to make S[0:i] = 0, S[i+1:N-1] = 1.
    for (int i = 0; i < S.size(); ++i) {
      int post_zeros = (N - i) - (total_ones - pre_ones[i]);
      result = min(result, pre_ones[i] + post_zeros);
    }
    return result;
  }
};
