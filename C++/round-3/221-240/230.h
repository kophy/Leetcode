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
        stack<TreeNode *> data;
        int result = INT_MAX;
        while (root) {
            data.push(root);
            root = root->left;
        }
        for (int i = 0; i < k && !data.empty(); ++i) {
            auto curr = data.top();
            data.pop();
            result = curr->val;
            curr = curr->right;
            while (curr) {
                data.push(curr);
                curr = curr->left;
            }
        }
        return result;
    }
};