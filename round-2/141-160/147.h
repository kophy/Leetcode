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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);

        while (head) {
            auto prev = &dummy;
            while (prev->next && prev->next->val <= head->val)
                prev = prev->next;
            auto tail = head->next;
            head->next = prev->next;
            prev->next = head;
            head = tail;
        }

        return dummy.next;
    }
};