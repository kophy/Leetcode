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
        if (head == NULL || head->next == NULL)
            return head;
        ListNode dummy(0), *curr = &dummy;
        while (head) {
            ListNode *pivot = head;
            int same = 0;
            while (head->next && head->next->val == head->val) {
                head = head->next;
                ++same;
            }
            head = head->next;
            if (same == 0) {
                curr->next = pivot;
                curr = curr->next;
                curr->next = NULL;
            }
        }
        return dummy.next;
    }
};