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
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second = NULL;

        /* basic idea is to implement a in-order iterator of BST */
        stack<TreeNode *> data;
        while (root) {
            data.push(root);
            root = root->left;
        }

        /* old dummy trick */
        TreeNode dummy(INT_MIN), *last = &dummy;
        while (!data.empty()) {
            TreeNode *curr = data.top();
            data.pop();

            /* update stack to make the iterator work */
            auto temp = curr->right;
            while (temp) {
                data.push(temp);
                temp = temp->left;
            }

            /* when a reverse pair appears */
            if (last->val > curr->val) {
                if (first == NULL)
                    first = last;
                second = curr;		// important: don't use else! think about when two adjacent nodes are swaped
            }

            /* update last node */
            last = curr;
        }
        if (first != NULL && second != NULL)
            swap(first->val, second->val);
    }
};