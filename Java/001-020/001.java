public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        Map<Integer, Integer> val2idx = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; ++i) {
            if (val2idx.containsKey(target - nums[i])) {
                result[0] = val2idx.get(target - nums[i]);
                result[1] = i;
                break;
            }
            val2idx.put(nums[i], i);
        }
        return result;
    }
}