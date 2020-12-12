class Solution {
public:
    int numberOfWays(int num_people) {
        vector<long> dp(num_people + 1, -1);
        dp[0] = 1;
        M = pow(10, 9) + 7;
        return helper(dp, num_people);
    }
    
private:
    int M;
    
    long helper(vector<long> &dp, int n) {
        if (n % 2 == 1) {
            return 0;
        }
        if (dp[n] > 0) {
            return dp[n];
        }
        
        dp[n] = 0;
        for (int left = 0; left <= n - 2; ++left) {
            int right = n - 2 - left;
            dp[n] += helper(dp, left) * helper(dp, right);
            dp[n] %= M;
        }
        return dp[n];
    }
};