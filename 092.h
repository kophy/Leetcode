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
        ListNode dummy(0), *prev = &dummy;
        dummy.next = head;
        int i = 0;
        for (; i < m - 1; ++i)
            prev = prev->next;
        ListNode *pivot = prev->next;
        for (; i < n - 1; ++i) {
            swap(prev->next, pivot->next->next);
            swap(prev->next, pivot->next);
        }
        return dummy.next;
    }
};