public class Solution {
    public String[] findRelativeRanks(int[] nums) {
        Map<Integer, Integer> rank2idx = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; ++i)
            rank2idx.put(nums[i], i);
        Arrays.sort(nums);
        for (int i = 0, j = nums.length - 1; i < j; ++i, --j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        
        String[] medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        String[] result = new String[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            int idx = rank2idx.get(nums[i]);
            result[idx] = (i < 3)? medals[i] : (i + 1 + "");
        }
        return result;
    }
}