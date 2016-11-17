public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = {-1, -1};
        HashMap<Integer, Integer> val2idx = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; ++i) {
            if (val2idx.get(target - nums[i]) != null) {
                result[0] = val2idx.get(target - nums[i]);
                result[1] = i;
                break;
            }
            val2idx.put(nums[i], i);
        }
        return result;
    }
}