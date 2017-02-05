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
    /* Pay attention to problem description!!! */
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd_dummy(0), *odd_curr = &odd_dummy;
        ListNode eve_dummy(0), *eve_curr = &eve_dummy;

        while (head) {
            if (head) {
                odd_curr->next = head;
                odd_curr = odd_curr->next;
                head = head->next;
            }
            if (head) {
                eve_curr->next = head;
                eve_curr = eve_curr->next;
                head = head->next;
            }
        }
        odd_curr->next = eve_dummy.next;
        eve_curr->next = NULL;
        return odd_dummy.next;
    }
};