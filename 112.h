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
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSum_helper(root, sum, 0);
    }
private:
    bool hasPathSum_helper(TreeNode* root, int sum, int tempsum) {
        if (!root)
            return false;
        tempsum += root->val;
        if (!root->left && !root->right)
            return (tempsum == sum);
        else
            return hasPathSum_helper(root->left, sum, tempsum) ||
                   hasPathSum_helper(root->right, sum, tempsum);
    }
};