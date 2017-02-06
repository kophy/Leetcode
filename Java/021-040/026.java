public class Solution {
    public int removeDuplicates(int[] nums) {
        int len = 0;
        for (int num : nums)
            if (len == 0 || nums[len - 1] != num)
                nums[len++] = num;
        return len;
    }
}