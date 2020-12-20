class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    if (arr.empty()) {
      return 0;
    }
    int N = arr.size();
    vector<int> memo(N + 1, 0);
    return helper(arr, k, 0, memo);
  }

private:
  int helper(vector<int> &arr, int k, int begin, vector<int> &memo) {
    if (memo[begin] > 0) {
      return memo[begin];
    }
    if (begin >= arr.size()) {
      return 0;
    }

    int curr_max = memo[begin];
    for (int i = begin; i < arr.size() && i < begin + k; ++i) {
      curr_max = max(curr_max, arr[i]);
      memo[begin] = max(memo[begin], curr_max * (i - begin + 1) +
                                         helper(arr, k, i + 1, memo));
    }
    return memo[begin];
  }
};