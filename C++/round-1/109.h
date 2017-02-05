/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST_help(head, nullptr);
    }
private:
    TreeNode* sortedListToBST_help(ListNode* head, ListNode* tail) {
        if (head == tail)
            return nullptr;
        ListNode* slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST_help(head, slow);
        root->right = sortedListToBST_help(slow->next, tail);
        return root;
    }
};