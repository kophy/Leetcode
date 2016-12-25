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
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd_head(0), *odd_curr = &odd_head;
        ListNode eve_head(0), *eve_curr = &eve_head;
        int count = 0;
        while (head) {
            ListNode *tail = head->next;
            head->next = NULL;
            if (count % 2 == 1) {
                odd_curr->next = head;
                odd_curr = odd_curr->next;
            } else {
                eve_curr->next = head;
                eve_curr = eve_curr->next;
            }
            ++count;
            head = tail;
        }
        eve_curr->next = odd_head.next;
        return eve_head.next;
    }
};