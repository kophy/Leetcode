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
    int kthSmallest(TreeNode* root, int k) {
        int count = 1;
        stack<TreeNode *> data;
        while (root) {
            data.push(root);
            root = root->left;
        }
        while (!data.empty()) {
            TreeNode *curr = data.top();
            if (count++ == k)
                return curr->val;
            data.pop();
            curr = curr->right;
            while (curr) {
                data.push(curr);
                curr = curr->left;
            }
        }
        return 0;
    }
};