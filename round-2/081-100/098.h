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
        long lower = LONG_MIN, upper = LONG_MAX;
        return isValid(root, lower, upper);
    }

private:
    bool isValid(TreeNode *root, long lower_bound, long upper_bound) {
        if (!root)
            return true;
        else if (root->val <= lower_bound || root->val >= upper_bound)
            return false;
        else
            return isValid(root->left, lower_bound, root->val) &&
                   isValid(root->right, root->val, upper_bound);
    }
};