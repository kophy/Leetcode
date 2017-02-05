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
        if (root->left == NULL)
            return 1;
        int left_depth = 0, right_depth = 0;
        for (auto curr = root->left; curr; curr = curr->left)
            ++left_depth;
        for (auto curr = root->left; curr; curr = curr->right)
            ++right_depth;
        if (left_depth == right_depth)
            return ((1 << left_depth) - 1) + 1 + countNodes(root->right);
        else
            return countNodes(root->left) + 1 + ((1 << right_depth) - 1);
    }
};