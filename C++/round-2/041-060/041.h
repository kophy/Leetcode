class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0 || nums[i] > N)
                nums[i] = N + 1;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int d = abs(nums[i]);
            if (d <= N)
                nums[d - 1] = -abs(nums[d - 1]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                return i + 1;
        }
        return N + 1;
    }
};