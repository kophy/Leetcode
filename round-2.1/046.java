public class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (nums.length > 0) {
            boolean[] used = new boolean[nums.length];
            for (int i = 0; i < used.length; ++i)
                used[i] = false;
            int[] temp = new int[nums.length];
            permute_help(result, nums, used, temp, 0);
        }
        return result;
    }

    private void permute_help(List<List<Integer>> result, int[] nums, boolean[] used, int[] temp, int pos) {
        if (pos == nums.length) {
            List<Integer> l = new ArrayList<Integer>();
        for (int num : temp)
                l.add(num);
            result.add(l);
        }
        for (int i = 0; i < nums.length; ++i) {
            if (used[i])
                continue;
            used[i] = true;
            temp[pos] = nums[i];
            permute_help(result, nums, used, temp, pos + 1);
            used[i] = false;
        }
    }
}