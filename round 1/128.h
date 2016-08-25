class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        map<int, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            if (count.find(nums[i]) == count.end()) {
                int left = 0, right = 0;
                if (count.find(nums[i] - 1) != count.end())
                    left = count[nums[i] - 1];
                if (count.find(nums[i] + 1) != count.end())
                    right = count[nums[i] + 1];
                int sum = left + right + 1;
                result = max(result, sum);

                count[nums[i]] = sum;
                count[nums[i] - left] = sum;
                count[nums[i] + right] = sum;
            }
        }
        return result;
    }
};