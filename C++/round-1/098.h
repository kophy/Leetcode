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
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
private:
    bool isValid(TreeNode *root, long min_val, long max_val) {
        if (!root)
            return true;
        if (root->val <= min_val || root->val >= max_val)
            return false;
        return isValid(root->left, min_val, root->val) && isValid(root->right, root->val, max_val);
    }
};