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
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return rob_help(root, l, r);
    }

private:
    int rob_help(TreeNode *root, int &l, int &r) {
        if (root == nullptr)
            return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = rob_help(root->left, ll, lr);
        r = rob_help(root->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};