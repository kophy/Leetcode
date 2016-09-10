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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (true) {
            if (fast == NULL || fast->next == NULL)
                return NULL;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        /*  a + x = (2a + 2x) mod C
        	a = (C - x) mod C
        */
        ListNode *pivot = head;
        while (slow != pivot) {
            slow = slow->next;
            pivot = pivot->next;
        }
        return pivot;
    }
};