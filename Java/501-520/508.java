/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int[] findFrequentTreeSum(TreeNode root) {
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        traverseTreeSum(count, root);
        int max_count = 0;
        for (Integer sum : count.keySet())
            max_count = Math.max(max_count, count.get(sum));
        List<Integer> result = new LinkedList<Integer>();
        for (Integer sum : count.keySet())
            if (count.get(sum) == max_count)
                result.add(sum);
        
        /* this part is fantastic! */
        return result.stream().mapToInt(x->x).toArray();
    }
    
    private int traverseTreeSum(Map<Integer, Integer> count, TreeNode root) {
        if (root == null)
            return 0;
        int left_sum = traverseTreeSum(count, root.left), right_sum = traverseTreeSum(count, root.right);
        int sum = left_sum + root.val + right_sum;
        count.put(sum, count.getOrDefault(sum, 0) + 1);
        return sum;
    }
}