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

        /* test whether left subtree is completed */
        auto left = root->left, right = root->left;
        int height = 0;
        while (right) {
            left = left->left;
            right = right->right;
            ++height;
        }
        int subtree_count = (1 << height) - 1;

        // case 1: left subtree is completed, we don't konw whether right subtree is.
        if (left == NULL)
            return 1 + subtree_count + countNodes(root->right);
        // case 2: left subtree is not completed, we now konw right subtree is.
        else
            return 1 + countNodes(root->left) + subtree_count;
    }
};