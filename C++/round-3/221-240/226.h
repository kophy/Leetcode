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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode *> data;
        if (root)
            data.push(root);
        while (!data.empty()) {
            TreeNode *curr = data.front();
            data.pop();
            swap(curr->left, curr->right);
            if (curr->left)
                data.push(curr->left);
            if (curr->right)
                data.push(curr->right);
        }
        return root;
    }
};