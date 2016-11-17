public class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0, j = 0;
        while (i < nums.length) {
            int temp = nums[i];
            nums[j++] = nums[i++];
            while (i < nums.length && nums[i] == temp)
                ++i;
        }
        return j;
    }
}