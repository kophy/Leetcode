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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0), *curr = &dummy;
        while (head && head->next) {
            ListNode *tail = head->next->next;
            curr->next = head->next;
            curr = curr->next;
            curr->next = head;
            curr = curr->next;
            head = tail;
        }
        curr->next = head;
        return dummy.next;
    }
};