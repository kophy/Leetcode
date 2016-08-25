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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pm = &dummy;
        int i = 0;
        for (; i < m - 1; ++i)
            pm = pm->next;

        ListNode *reverse = pm;
        ListNode *prev = reverse->next;
        ListNode *curr = prev->next;
        for (; i < n - 1; ++i) {
            prev->next = curr->next;
            curr->next = reverse->next;
            reverse->next = curr;
            curr = prev->next;
        }
        return dummy.next;
    }
};