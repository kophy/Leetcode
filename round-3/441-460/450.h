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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else {
            if (root->left == NULL || root->right == NULL) {
                TreeNode *temp = root->left? root->left : root->right;
                delete root;
                root = temp;
            } else {
                TreeNode *target = root->right;
                while (target->left)
                    target = target->left;
                swap(root->val, target->val);
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};