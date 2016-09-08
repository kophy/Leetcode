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
    void flatten(TreeNode* root) {
        TreeNode dummy(0), *curr = &dummy;
        stack<TreeNode *> data;
        if (root)
            data.push(root);
        while (!data.empty()) {
            TreeNode *temp = data.top();
            data.pop();
            if (temp->right)
                data.push(temp->right);
            if (temp->left)
                data.push(temp->left);
            curr->right = temp;
            curr = curr->right;
            curr->left = curr->right = NULL;
        }
    }
};