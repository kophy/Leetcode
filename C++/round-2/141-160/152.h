class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() < 0)
            return 0;
        int max_product = nums[0];
        int curr_max = nums[0], curr_min = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int temp = curr_max;

            // similar to max sum subarray
            // always include current element in the product
            curr_max = max(curr_max * nums[i], max(curr_min * nums[i], nums[i]));
            curr_min = min(temp * nums[i], min(curr_min * nums[i], nums[i]));
            max_product = max(max_product, curr_max);
        }
        return max_product;
    }
};