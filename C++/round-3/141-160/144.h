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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> data;
        if (root)
            data.push(root);
        while (!data.empty()) {
            auto curr = data.top();
            data.pop();
            result.push_back(curr->val);
            if (curr->right)
                data.push(curr->right);
            if (curr->left)
                data.push(curr->left);
        }
        return result;
    }
};