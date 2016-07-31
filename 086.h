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
        ListNode less(0), *pless = &less;
        ListNode greater(0), *pgreater = &greater;
        while (head) {
            if (head->val < x) {
                pless->next = head;
                head = head->next;
                pless = pless->next;
                pless->next = NULL;
            } else {
                pgreater->next = head;
                head = head->next;
                pgreater = pgreater->next;
                pgreater->next =NULL;
            }
        }
        pless->next = greater.next;
        return less.next;
    }
};