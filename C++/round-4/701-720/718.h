class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int result = 0;
        int M = A.size(), N = B.size();
        vector<vector<int>> dp(2, vector<int>(N + 1, 0));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i] == B[j])
                    dp[(i + 1) % 2][j + 1] = dp[i % 2][j] + 1;
                else
                    dp[(i + 1) % 2][j + 1] = 0;
                result = max(result, dp[(i + 1) % 2][j + 1]);
            }
        }
        return result;
    }
};