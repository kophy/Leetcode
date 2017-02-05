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
        ListNode *odd_head = new ListNode(0);
        ListNode *odd_curr = odd_head;
        ListNode *even_head = new ListNode(0);
        ListNode *even_curr = even_head;
        int count = 1;

        while (head) {
            if (count % 2) {
                odd_curr->next = head;
                odd_curr = odd_curr->next;
            } else {
                even_curr->next = head;
                even_curr = even_curr->next;
            }
            head = head->next;
            ++count;
        }

        odd_curr->next = even_head->next;
        even_curr->next = NULL;
        return odd_head->next;
    }
};