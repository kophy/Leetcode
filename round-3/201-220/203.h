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
        while (head != nullptr) {
            auto tail = head->next;
            head->next = nullptr;
            if (head->val != val) {
                curr->next = head;
                curr = curr->next;
            }
            head = tail;
        }
        return dummy.next;
    }
};