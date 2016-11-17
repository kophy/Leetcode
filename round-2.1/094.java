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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        if (root != null)
            inorder_help(result, root);
        return result;
    }

    private void inorder_help(List<Integer> result, TreeNode root) {
        if (root == null)
            return;
        if (root.left != null)
            inorder_help(result, root.left);
        result.add(root.val);
        if (root.right != null)
            inorder_help(result, root.right);
    }
}