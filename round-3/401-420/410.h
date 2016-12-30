class Solution {
public:
    int splitArray(vector<int> &nums, int m) {
        long min_sum = INT_MIN, max_sum = 0;
for (int num : nums) {
            if (min_sum < num)
                min_sum = num;
            max_sum += num;
        }
        long low = min_sum, high = max_sum;
        while (low < high) {
            long middle = low + (high - low) / 2;
            if (!isPossibleSplit(nums, m, middle))
                low = middle + 1;
            else
                high = middle;
        }
        return low;
    }

private:
    bool isPossibleSplit(vector<int> &nums, int m, long sum) {
        int temp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            temp += nums[i];
            if (temp > sum) {
                if (--m <= 0)
                    return false;
                temp = nums[i];
            }
        }
        return true;
    }
};