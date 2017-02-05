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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;

        /* find the node before the m-th node */
        ListNode *pivot = &dummy;
        for (int i = 0; i < m - 1; ++i)
            pivot = pivot->next;

        ListNode *rest = pivot->next;
        for (int i = m; i <= n; ++i) {		// important: the range is from m to n inclusive
            // head insert (n - m + 1) nodes
            ListNode *tail = rest->next;
            rest->next = pivot->next;
            pivot->next = rest;
            rest = tail;
        }

        /* find the n-th node */
        for (int i = m; i <= n; ++i)
            pivot = pivot->next;
        pivot->next = rest;
        return dummy.next;
    }
};