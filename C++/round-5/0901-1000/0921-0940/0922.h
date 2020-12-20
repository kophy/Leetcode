class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &A) {
    vector<int> result(A.size(), 0);
    int even = 0, odd = 1;
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] % 2 == 0) {
        result[even] = A[i];
        even += 2;
      } else {
        result[odd] = A[i];
        odd += 2;
      }
    }
    return result;
  }
};
