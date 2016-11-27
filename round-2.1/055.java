public class Solution {
    public boolean canJump(int[] nums) {
        if (nums == null || nums.length == 0)
            return false;
        int max_reach = 0;
        for (int i = 0; i <= max_reach; ++i) {
            max_reach = Math.max(max_reach, i + nums[i]);
            if (max_reach >= nums.length - 1)
                return true;
        }
        return false;
    }
}