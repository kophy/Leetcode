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
        return balance_helper(root, depth);
    }
private:
    bool balance_helper(TreeNode* root, int &depth) {
        if (!root) {
            depth = 0;
            return true;
        }
        if (!root->left && !root->right) {
            depth = 1;
            return true;
        }
        int left_depth;
        bool left_flag = balance_helper(root->left, left_depth);
        int right_depth;
        bool right_flag = balance_helper(root->right, right_depth);
        depth = max(left_depth, right_depth) + 1;
        return left_flag && right_flag && (abs(left_depth - right_depth) <= 1);
    }
};