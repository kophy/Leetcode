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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;

        TreeNode *curr = root;
        int kthsmallest = INT_MIN;

        while (curr != NULL) {
            // case 1: no predecessor
            if (curr->left == NULL) {

                // can't simply return.. we have to fix BST structure
                if (++count == k)
                    kthsmallest = curr->val;
                curr = curr->right;
            }

            // case 2: has a predecessor
            else {
                TreeNode *prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                    prev = prev->right;

                // case 2.1: the predecessor hasn't been visited
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                // case 2.2: the predecessor has been visited
                else {
                    prev->right = NULL;
                    if (++count == k)
                        kthsmallest = curr->val;
                    curr = curr->right;
                }
            }
        }
        return kthsmallest;
    }
};