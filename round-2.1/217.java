public class Solution {
    public boolean containsDuplicate(int[] nums) {
        if (nums == null || nums.length <= 1)
            return false;
        HashSet<Integer> data = new HashSet<>();
        for (int num : nums) {
            if (data.contains(num))
                return true;
            data.add(num);
        }
        return false;
    }
}