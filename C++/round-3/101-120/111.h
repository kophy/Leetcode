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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int min_depth = INT_MAX;
        minDepth_helper(min_depth, root, 0);
        return min_depth;
    }
    
private:
    void minDepth_helper(int &min_depth, TreeNode *root, int curr_depth) {
        ++curr_depth;
        if (root->left == NULL && root->right == NULL) {
            min_depth = min(min_depth, curr_depth);
            return;
        }
        if (root->left)
            minDepth_helper(min_depth, root->left, curr_depth);
        if (root->right)
            minDepth_helper(min_depth, root->right, curr_depth);
    }
};