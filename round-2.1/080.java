public class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length <= 1)
            return nums.length;
        int i = 0, j = 0;
        while (i < nums.length) {
            int count = 0;
            while (i + count < nums.length && nums[i + count] == nums[i]) {
                ++count;
                if (count <= 2)
                    nums[j++] = nums[i];
            }
            i += count;
        }
        return j;
    }
}