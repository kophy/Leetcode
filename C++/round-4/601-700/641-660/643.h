class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        double result = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (i >= k)
                sum -= nums[i - k];
            if (i >= k - 1)
                result = max(result, sum * 1.0 / k);
        }
        return result;
    }
};