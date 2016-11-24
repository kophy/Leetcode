public class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        TreeSet<Integer> values = new TreeSet<>();
        for (int i = 0; i < nums.length; ++i) {
            Integer f = values.floor(nums[i] + t);
            Integer c = values.ceiling(nums[i] - t);
            if ((f != null && f >= nums[i]) || (c != null && c <= nums[i]))
                return true;
            values.add(nums[i]);
            if (i >= k)
                values.remove(nums[i - k]);
        }
        return false;
    }
}