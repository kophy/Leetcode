public class Solution {
    public void sortColors(int[] nums) {
        int i = 0, j = 0, k = nums.length;
        while (i < k) {
            if (nums[i] == 0)
                swap(nums, i++, j++);
            else if (nums[i] == 1)
                ++i;
            else
                swap(nums, i, --k);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}