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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0), *curr = &dummy;
        while (head != nullptr) {
            ListNode *tail = head->next;
            head->next = nullptr;
            if (curr == &dummy || curr->val != head->val) {
                curr->next = head;
                curr = curr->next;
            }
            head = tail;
        }
        return dummy.next;
    }
};