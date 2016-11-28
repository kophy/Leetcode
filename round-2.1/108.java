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
    public TreeNode sortedArrayToBST(int[] nums) {
        return convert(nums, 0, nums.length - 1);
    }

    private TreeNode convert(int[] nums, int s, int e) {
        if (s > e)
            return null;
        int m = (s + e) / 2;
        TreeNode root = new TreeNode(nums[m]);
        root.left = convert(nums, s, m - 1);
        root.right = convert(nums, m + 1, e);
        return root;
    }
}