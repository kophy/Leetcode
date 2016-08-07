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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        maxPathSumDown(max_sum, root);
        return max_sum;
    }
private:
    int maxPathSumDown(int &max_sum, TreeNode *root) {
        if (!root)
            return 0;
        int left = max(0, maxPathSumDown(max_sum, root->left));
        int right = max(0, maxPathSumDown(max_sum, root->right));
        max_sum = max(max_sum, left + right + root->val);
        return max(left, right) + root->val;
    }
};