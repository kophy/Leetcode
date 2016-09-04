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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> data;
        if (root)
            data.push(root);
        while (!data.empty()) {
            TreeNode *temp = data.top();
            data.pop();
            result.push_back(temp->val);
            if (temp->right)
                data.push(temp->right);
            if (temp->left)
                data.push(temp->left);
        }
        return result;
    }
};