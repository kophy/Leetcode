class Solution {
 public:
  int maxSumTwoNoOverlap(vector<int> &A, int L, int M) {
    vector<int> presums(A.size() + 1, 0);
    for (int i = 0; i < A.size(); ++i) {
      presums[i + 1] = presums[i] + A[i];
    }
    return max(maxSumTwoNoOverlapHelper(presums, L, M),
               maxSumTwoNoOverlapHelper(presums, M, L));
  }

 private:
  int maxSumTwoNoOverlapHelper(vector<int> &presums, int L, int M) {
    int result = 0;
    for (int i = 0; i + L + M < presums.size(); ++i) {
      int sum_L = presums[i + L] - presums[i];
      int sum_M = 0;
      for (int j = i + L; j + M < presums.size(); ++j) {
        sum_M = max(sum_M, presums[j + M] - presums[j]);
      }
      result = max(result, sum_L + sum_M);
    }
    return result;
  }
};

class Solution {
 public:
  int maxSumTwoNoOverlap(vector<int> &A, int L, int M) {
    vector<int> presums(A.size() + 1, 0);
    for (int i = 0; i < A.size(); ++i) {
      presums[i + 1] = presums[i] + A[i];
    }
    return max(maxSumTwoNoOverlapHelper(presums, L, M),
               maxSumTwoNoOverlapHelper(presums, M, L));
  }

 private:
  int maxSumTwoNoOverlapHelper(vector<int> &presums, int L, int M) {
    int result = 0;
    stack<int> max_sum_M;
    for (int j = (int)presums.size() - M - 1; j >= L; --j) {
      int sum_M = presums[j + M] - presums[j];
      max_sum_M.push(max_sum_M.empty() ? sum_M : max(sum_M, max_sum_M.top()));
    }

    for (int i = 0; i + L + M < presums.size(); ++i) {
      int sum_L = presums[i + L] - presums[i];
      int sum_M = max_sum_M.top();
      result = max(result, sum_L + sum_M);
      max_sum_M.pop();
    }
    return result;
  }
};
