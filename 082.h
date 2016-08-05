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
        ListNode dummy(0);
        ListNode *curr = &dummy;

        while (head) {
            if (!head->next || head->val != head->next->val) {
                curr->next = head;
                head = head->next;
                curr = curr->next;
                curr->next = nullptr;
            } else {
                int prev = head->val;
                while (head && head->val == prev)
                    head = head->next;
            }
        }
        return dummy.next;
    }
};