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
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (root != null)
            bfs(result, root, 0);
        return result;
    }

    private void bfs(List<List<Integer>> result, TreeNode root, int level) {
        if (result.size() < level + 1)
            result.add(new ArrayList<Integer>());
        result.get(level).add(root.val);
        if (root.left != null)
            bfs(result, root.left, level + 1);
        if (root.right != null)
            bfs(result, root.right, level + 1);
    }
}