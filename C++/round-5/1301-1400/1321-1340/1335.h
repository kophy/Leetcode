class Solution {
public:
    int minDifficulty(vector<int> &jobDifficulty, int d) {
        dp = vector<vector<int>>(jobDifficulty.size(), vector<int>(d + 1, 0));
        return minDifficulty(jobDifficulty, 0, d);
    }
    
private:
    vector<vector<int>> dp;
    
    int minDifficulty(vector<int> &jobDifficulty, int begin, int d) {
        if (d <= 0) {
            return begin >= jobDifficulty.size()? 0 : -1;
        }
        if (begin + d > jobDifficulty.size()) {
            return -1;
        }
        
        if (dp[begin][d] != 0) {
            return dp[begin][d];
        }
        
        int first = jobDifficulty[begin];
        int total = INT_MAX;
        for (int i = begin; i <= jobDifficulty.size() - d; ++i) {
            first = std::max(first, jobDifficulty[i]);
            int rest = minDifficulty(jobDifficulty, i + 1, d - 1);
            if (rest >= 0) {
                total = std::min(total, first + rest);
            }
        }
        
        if (total == INT_MAX) {
            total = -1;
        }
        dp[begin][d] = total;
        return dp[begin][d];
    }
};

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int N = jobDifficulty.size();
        vector<vector<int>> dp(N + 1, vector<int>(d + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 0; i < N; ++i) {
            dp[i + 1][0] = -1;
        }
        for (int j = 0; j < d; ++j) {
            dp[0][j + 1] = -1;
        }
        
        for (int j = 1; j <= d; ++j) {
            for (int i = 1; i <= N; ++i) {
                int first = INT_MIN;
                int total = INT_MAX;
                for (int k = i; k >= 1; --k) {
                    first = std::max(first, jobDifficulty[k - 1]);
                    int rest = dp[k - 1][j - 1];
                    if (rest != -1) {
                        total = std::min(total, first + rest);
                    }
                }
                dp[i][j] = (total == INT_MAX)? -1 : total;
            }
        }
        return dp[N][d];
    }
};