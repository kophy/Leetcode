public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        result.add(new ArrayList<Integer>());
        if (nums == null || nums.length == 0)
            return result;
        for(int num : nums) {
            int size = result.size();
            for (int i = 0; i < size; ++i) {
                List<Integer> temp = new ArrayList<Integer>(result.get(i));
                temp.add(num);
                result.add(temp);
            }
        }
        return result;
    }
}