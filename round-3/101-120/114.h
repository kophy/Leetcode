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
        if (root != nullptr)
            data.push(root);
        while (!data.empty()) {
            TreeNode *temp = data.top();
            data.pop();
            if (temp->right)
                data.push(temp->right);
            temp->right = nullptr;
            if (temp->left)
                data.push(temp->left);
            temp->left = nullptr;
            curr->right = temp;
            curr = curr->right;
        }
        root = dummy.right;
    }
};