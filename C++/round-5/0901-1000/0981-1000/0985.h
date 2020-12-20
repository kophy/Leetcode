class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int> &A,
                                  vector<vector<int>> &queries) {
    int sum = 0;
    for (int x : A) {
      if (x % 2 == 0) {
        sum += x;
      }
    }
    vector<int> result;
    for (const auto &query : queries) {
      int val = query[0], idx = query[1];
      if (A[idx] % 2 == 0 && val % 2 == 0) {
        sum += val;
      } else if (A[idx] % 2 == 0 && val % 2 != 0) {
        sum -= A[idx];
      } else if (A[idx] % 2 != 0 && val % 2 != 0) {
        sum += A[idx] + val;
      }
      A[idx] += val;
      result.push_back(sum);
    }
    return result;
  }
};
