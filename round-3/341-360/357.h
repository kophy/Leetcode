class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int result = 0;
        vector<bool> used(10, false);
        backtrackUniqueDigits(result, used, n, 0);
        return result;
    }

private:
    void backtrackUniqueDigits(int &result, vector<bool> &used, int n, int temp) {
        if (n >= 0)
            ++result;
        if (n <= 0)
            return;
        for (int i = 0; i < 10; ++i) {
            if (temp * 10 + i == 0 || used[i])
                continue;
            used[i] = true;
            backtrackUniqueDigits(result, used, n - 1, temp * 10 + i);
            used[i] = false;
        }
    }
};