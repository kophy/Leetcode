class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int N = A.size();
        vector<vector<double>> dp(N + 1, vector<double>(K + 1, -1));
        dp[0][0] = 0;
        
        for (int k = 0; k <= K; ++k) {
            dp[0][k] = 0;
        }
        
        for (int k = 1; k <= K; ++k) {
            for (int i = 1; i <= N; ++i) {
                double curr_sum = 0.0;
                double curr_count = 0;
                for (int j = i; j >= 1; --j) {
                    curr_sum += A[j - 1];
                    curr_count += 1;
                    if (dp[j - 1][k - 1] < 0) {
                        continue;
                    }
                    dp[i][k] = std::max(dp[i][k], (curr_sum / curr_count) + dp[j - 1][k - 1]);
                }
            }
        }
        return dp[N][K];
    }
};