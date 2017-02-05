class Solution {
public:
    int maxRotateFunction(vector<int> &A) {
        if (A.size() == 0)
            return 0;
        int rotate = 0;
        for (int i = 0; i < A.size(); ++i)
            rotate += i * A[i];
        int max_rotate = rotate;

        int N = A.size(), sum = accumulate(A.begin(), A.end(), 0);
        for (int i = 1; i <= N; ++i) {
            rotate = rotate - sum + N * A[i - 1];
            max_rotate = max(max_rotate, rotate);
        }
        return max_rotate;
    }
};