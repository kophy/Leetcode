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
        return isSymmetric(root, root);
    }
    
private:
    bool isSymmetric(TreeNode *root1, TreeNode *root2) {
        if (root1 == NULL && root2 == NULL)
            return true;
        else if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
            return false;
        else
            return (root1->val == root2->val) && isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }
};