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
    bool isBalanced(TreeNode* root) {
        int depth;
        return balance(root, depth);
    }

private:
    bool balance(TreeNode *root, int &depth) {
        if (root == NULL) {
            depth = 0;
            return true;
        }
        int left_depth, right_depth;
        bool left_balanced = balance(root->left, left_depth);
        bool right_balanced = balance(root->right, right_depth);
        depth = max(left_depth, right_depth) + 1;
        return left_balanced && right_balanced && abs(left_depth - right_depth) <= 1;
    }
};