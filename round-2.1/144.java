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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> data = new Stack<>();
        if (root != null)
            data.add(root);
        while (!data.isEmpty()) {
            TreeNode temp = data.pop();
            result.add(temp.val);
            if (temp.right != null)
                data.add(temp.right);
            if (temp.left != null)
                data.add(temp.left);
        }
        return result;
    }
}