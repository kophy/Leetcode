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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* curr = head;
        while(curr->next->next)
            curr = curr->next;
        ListNode* tail = curr->next;
        curr->next = NULL;
        tail->next = reverseList(head);

        return tail;
    }
};