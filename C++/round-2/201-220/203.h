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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0), *curr = &dummy;
        while (head) {
            if (head->val == val) {
                auto temp = head;
                head = head->next;
                delete temp;
            } else {
                curr->next = head;
                head = head->next;
                curr = curr->next;
            }
        }
        curr->next = NULL;
        return dummy.next;
    }
};