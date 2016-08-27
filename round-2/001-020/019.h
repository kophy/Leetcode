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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;
        for (int i = 0; i < n; ++i)
            fast = fast->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *target = slow->next;
        slow->next = slow->next->next;
        delete target;
        return dummy.next;
    }
};