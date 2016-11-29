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
    public boolean isSymmetric(TreeNode root) {
        return symmetric(root, root);
    }

    private boolean symmetric(TreeNode p, TreeNode q) {
        if (p == null && q == null)
            return true;
        else if (p == null ^ q == null)
            return false;
        else
            return p.val == q.val && symmetric(p.left, q.right) && symmetric(p.right, q.left);
    }
}