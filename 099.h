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
    void recoverTree(TreeNode *root) {
        lastnode = nullptr;
        first = second = nullptr;
        traverse(root);
        swap(first->val, second->val);
    }

    void traverse(TreeNode *root) {
        if (!root)
            return;
        traverse(root->left);
        if (lastnode) {
            if (root->val < lastnode->val) {
                if (first == nullptr)
                    first = lastnode;
                second = root;
            }
        }
        lastnode = root;
        traverse(root->right);
    }

private:
    TreeNode *lastnode;
    TreeNode *first, *second;
};