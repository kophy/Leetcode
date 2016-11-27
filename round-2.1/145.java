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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> data = new Stack<>();
        if (root != null)
            data.push(root);
        while (!data.isEmpty()) {
            TreeNode curr = data.peek();
            data.pop();
            result.add(curr.val);
            if (curr.left != null)
                data.push(curr.left);
            if (curr.right != null)
                data.push(curr.right);
        }
        Collections.reverse(result);
        return result;
    }
}