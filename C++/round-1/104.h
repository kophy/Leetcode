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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        else if (!root->left && !root->right)
            return 1;
        else if (root->left && !root->right)
            return maxDepth(root->left) + 1;
        else if (!root->left && root->right)
            return maxDepth(root->right) + 1;
        else
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};