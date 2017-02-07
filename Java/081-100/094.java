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
        List<Integer> result = new LinkedList<Integer>();
        Stack<TreeNode> data = new Stack<TreeNode>();
        while (root != null) {
            data.push(root);
            root = root.left;
        }
        while (!data.empty()) {
            TreeNode temp = data.pop();
            result.add(temp.val);
            temp = temp.right;
            while (temp != null) {
                data.push(temp);
                temp = temp.left;
            }
        }
        return result;
    }
}