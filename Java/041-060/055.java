public class Solution {
    public boolean canJump(int[] nums) {
        int reach = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (reach < i)
                return false;
            else if (reach >= nums.length - 1)
                return true;
            reach = Math.max(reach, i + nums[i]);
        }
        return false;
    }
}