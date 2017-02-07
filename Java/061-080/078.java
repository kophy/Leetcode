public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new LinkedList<List<Integer>>();
        result.add(new LinkedList<Integer>());
        for (int num : nums) {
            int len = result.size();
            for (int i = 0; i < len; ++i) {
                List<Integer> temp = new LinkedList<Integer>(result.get(i));
                temp.add(num);
                result.add(temp);
            }
        }
        return result;
    }
}