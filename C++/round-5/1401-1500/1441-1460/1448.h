/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int result = 0;
        helper(result, root, INT_MIN);
        return result;
    }
    
private:
    void helper(int &result, TreeNode *root, int prev_max) {
        if (root == nullptr) {
            return;
        }
        int curr_max = prev_max;
        if (root->val >= prev_max) {
            ++result;
            curr_max = root->val;
        }
        helper(result, root->left, curr_max);
        helper(result, root->right, curr_max);
    }
};