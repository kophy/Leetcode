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
    void pathSum_help(int &result, TreeNode *root, int sum, int temp, bool broken) {
        if (root == NULL)
            return;
        temp += root->val;
        if (temp == sum)
            ++result;
        pathSum_help(result, root->left, sum, temp, broken);
        pathSum_help(result, root->right, sum, temp, broken);
        if (!broken) {
            pathSum_help(result, root->left, sum, 0, true);
            pathSum_help(result, root->right, sum, 0, true);
        }
    }
};