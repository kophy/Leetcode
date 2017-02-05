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
        TreeLinkNode dummy(0);
        TreeLinkNode *curr = &dummy;
        while (root) {
            if (root->left) {
                curr->next = root->left;
                curr = curr->next;
            }
            if (root->right) {
                curr->next = root->right;
                curr = curr->next;
            }
            root = root->next;
            if (root == nullptr) {
                root = dummy.next;
                dummy.next = nullptr;
                curr = &dummy;
            }
        }
    }
};