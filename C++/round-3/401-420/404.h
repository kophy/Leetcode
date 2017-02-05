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
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        if (root != NULL)
            traverse(result, root, false);
        return result;
    }

private:
    void traverse(int &result, TreeNode *root, bool is_left) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            if (is_left)
                result += root->val;
            return;
        }
        traverse(result, root->left, true);
        traverse(result, root->right, false);
    }
};