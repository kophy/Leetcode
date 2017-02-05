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
        if (root == NULL)
            return;
        TreeNode dummy(0);
        TreeNode *curr = &dummy;

        stack<TreeNode *> data;
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
        root = dummy.right;
    }
};