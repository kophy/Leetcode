class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int result = 0;
        long product = 1;
        for (int begin = 0, end = 0; end < nums.size(); ++end) {
            product *= nums[end];
            while (begin <= end && product >= k)
                product /= nums[begin++];
            result += end - begin + 1;
        }
        return result;
    }
};
