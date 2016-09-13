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
        maxPathSum_help(max_sum, root);
        return max_sum;
    }

private:
    int maxPathSum_help(int &max_sum, TreeNode *root) {
        if (root == NULL)
            return 0;
        int left_sum  = maxPathSum_help(max_sum, root->left);
        int right_sum = maxPathSum_help(max_sum, root->right);

        /* 4 possible cases */
        // case 1: just the root node
        max_sum = max(max_sum, root->val);
        // case 2: root node and left path
        max_sum = max(max_sum, left_sum + root->val);
        // case 3: root node and right path
        max_sum = max(max_sum, right_sum + root->val);
        // case 4: root node and both paths
        max_sum = max(max_sum, left_sum + right_sum + root->val);

        // can't return case 4
        return max(root->val, max(left_sum, right_sum) + root->val);
    }
};