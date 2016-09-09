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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        int val = root->val;
        if (val == sum && root->left == NULL && root->right == NULL)
            return true;
        else
            return hasPathSum(root->left, sum - val) || hasPathSum(root->right, sum - val);
    }
};