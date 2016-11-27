/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class BSTIterator {
    private Stack<TreeNode> data;

    public BSTIterator(TreeNode root) {
        data = new Stack<>();
        while (root != null) {
            data.push(root);
            root = root.left;
        }
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !data.isEmpty();
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode next = data.pop();
        for (TreeNode curr = next.right; curr != null; curr = curr.left)
            data.push(curr);
        return next.val;
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = new BSTIterator(root);
 * while (i.hasNext()) v[f()] = i.next();
 */