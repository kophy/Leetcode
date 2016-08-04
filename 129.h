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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int curr = 0;
        sumNumbers_help(sum, root, curr);
        return sum;
    }
    void sumNumbers_help(int &sum, TreeNode *root, int curr) {
        if (!root)
            return;
        curr = curr * 10 + root->val;
        if (!root->left && !root->right)
            sum += curr;
        if (root->left)
            sumNumbers_help(sum, root->left, curr);
        if (root->right)
            sumNumbers_help(sum, root->right, curr);
    }
};