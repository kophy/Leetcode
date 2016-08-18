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
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->left;
        int height = 0;
        while(right != NULL) {
            ++height;
            left = left->left;
            right = right->right;
        }
        int cnt = (1 << height) - 1;
        if (left == NULL)
            return 1 + cnt + countNodes(root->right);
        else
            return 1 + cnt + countNodes(root->left);
    }
};