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
        int height = 0;
        return isBalanced_helper(root, height);
    }
    
private:
    bool isBalanced_helper(TreeNode *root, int &height) {
        if (root == NULL) {
            height = 0;
            return true;
        } else {
            int left_height = 0, right_height = 0;
            bool left_valid = isBalanced_helper(root->left, left_height);
            bool right_valid = isBalanced_helper(root->right, right_height);
            height = max(left_height, right_height) + 1;
            return left_valid && right_valid && abs(left_height - right_height) <= 1;
        }
    }
};