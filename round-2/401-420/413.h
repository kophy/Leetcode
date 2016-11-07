class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sum = 0, curr = 0;
        for (int i = 2; i < A.size(); ++i) {
            // 1. arithmetic subarray continue
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                ++curr;
                sum += curr;
            }
            // 2. arithemtic subarray break
            else
                curr = 0;
        }
        return sum;
    }
};