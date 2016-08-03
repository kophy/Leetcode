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
            ListNode *tail = head->next;
            ListNode *temp = &dummy;
            while (temp->next && temp->next->val < head->val)
                temp = temp->next;
            head->next = temp->next;
            temp->next = head;
            head = tail;
        }
        return dummy.next;
    }
};