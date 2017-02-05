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
    bool isSymmetric(TreeNode* root) {
        return symmetric(root, root);
    }

private:
    bool symmetric(TreeNode *root1, TreeNode *root2) {
        if (root1 == NULL && root2 == NULL)
            return true;
        else if (root1 == NULL ^ root2 == NULL)
            return false;
        else
            return (root1->val == root2->val) && symmetric(root1->left, root2->right) &&
                                                 symmetric(root1->right, root2->left);
    }
};