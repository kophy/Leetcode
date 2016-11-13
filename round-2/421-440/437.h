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
    int pathSum(TreeNode* root, int sum) {
        int result = 0;
        pathSum_help(result, root, sum, 0, false);
        return result;
    }

private:
    // allow at most one cut -- what about allowing k cuts?
    void pathSum_help(int &result, TreeNode *root, int target, int current, bool cutted) {
        if (root == NULL)
            return;
        if (current + root->val == target)
            ++result;
        pathSum_help(result, root->left, target, current + root->val, cutted);
        pathSum_help(result, root->right, target, current + root->val, cutted);
        if (!cutted) {
            pathSum_help(result, root->left, target, 0, true);
            pathSum_help(result, root->right, target, 0, true);
        }
    }
};