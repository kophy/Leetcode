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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> data;
        while (root) {
            data.push(root);
            root = root->left;
        }

        while (!data.empty()) {
            TreeNode *temp = data.top();
            data.pop();
            result.push_back(temp->val);
            temp = temp->right;
            while (temp) {
                data.push(temp);
                temp = temp->left;
            }
        }
        return result;
    }
};