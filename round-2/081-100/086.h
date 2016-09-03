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
    ListNode* partition(ListNode* head, int x) {
        ListNode small(0), *curr_small = &small;
        ListNode large(0), *curr_large = &large;
        for (; head; head = head->next) {
            if (head->val < x) {
                curr_small->next = head;
                curr_small = curr_small->next;
            } else {
                curr_large->next = head;
                curr_large = curr_large->next;
            }
        }
        curr_small->next = large.next;
        curr_large->next = NULL;
        return small.next;
    }
};