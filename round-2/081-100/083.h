/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *curr = head;
        while (curr) {
            if (curr->next && curr->next->val == curr->val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return head;
    }
};