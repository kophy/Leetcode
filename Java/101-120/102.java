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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new LinkedList<List<Integer>>();
        Queue<TreeNode> data = new LinkedList<TreeNode>();
        if (root != null)
            data.offer(root);
        while (!data.isEmpty()) {
            int count = data.size();
            List<Integer> currLevel = new LinkedList<Integer>();
            for (int i = 0; i < count; ++i) {
                TreeNode temp = data.poll();
                currLevel.add(temp.val);
                if (temp.left != null)
                    data.offer(temp.left);
                if (temp.right != null)
                    data.offer(temp.right);
            }
            result.add(currLevel);
        }
        return result;
    }
}