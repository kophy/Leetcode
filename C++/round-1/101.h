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
    bool isSymmetric(TreeNode *root) {
        return root? isSymmetric_help(root->left, root->right) : true;
    }
private:
    bool isSymmetric_help(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2)
            return true;
        if ((root1 && !root2) || (!root1 && root2) || (root1->val != root2->val))
            return false;
        bool sym1 = isSymmetric_help(root1->left, root2->right);
        bool sym2 = isSymmetric_help(root1->right, root2->left);
        return sym1 && sym2;
    }
};