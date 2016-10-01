/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode *root) {
        int l, r;
        return rob_help(root, l, r);
    }

private:
    int rob_help(TreeNode *root, int &l, int &r) {
        l = 0, r = 0;
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->val;
        int ll, lr, rl, rr;
        l = rob_help(root->left, ll, lr);
        r = rob_help(root->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};