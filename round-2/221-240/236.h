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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // case 1: can't descend anymore.
        if (root == NULL || root == p || root == q)
            return root;
        auto left  = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        // case 2: p and q belong to two different subtrees.
        if (left && right)
            return root;
        // case 3: p and q belong to the same subtree.
        else
            return left? left : right;
    }
};