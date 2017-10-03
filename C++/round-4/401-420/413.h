class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int count = 0, result = 0;
        for (int i = 2; i < A.size(); ++i) {
            // count records the number of slices ending with A[i]
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                // case 1: all slices ending with A[i - 1] slide by 1 + whole longest slice
				++count;
                result += count;
            } else {
				// case 2: no slice ending with A[i]
                count = 0;
            }
        }
        return result;
    }
};