/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode dummy(0), *curr = &dummy;

        // Actually when traversing each level, we are connecting its lower level.
        while (root) {
            /* connect left and right child they exist */
            if (root->left) {
                curr->next = root->left;
                curr = curr->next;
            }
            if (root->right) {
                curr->next = root->right;
                curr = curr->next;
            }

            /* move to next node */
            root = root->next;

            /* move to lower level if all nodes in this level is visited */
            if (!root) {
                root = dummy.next;
                dummy.next = NULL;
                curr = &dummy;
            }
        }
    }
};