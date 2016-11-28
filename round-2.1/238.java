public class Solution {
    public int[] productExceptSelf(int[] nums) {
        if (nums == null || nums.length == 0)
            return null;
        int[] result = new int[nums.length];
        for (int i = 0; i < nums.length; ++i)
            result[i] = 1;
        for (int i = 1; i < nums.length; ++i)
            result[i] = result[i - 1] * nums[i - 1];
        int temp = nums[nums.length - 1];
        for (int i = nums.length - 2; i >= 0; --i) {
            result[i] *= temp;
            temp *= nums[i];
        }
        return result;
    }
}