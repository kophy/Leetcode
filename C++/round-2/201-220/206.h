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
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        while(head) {
            ListNode *tail = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tail;
        }
        return dummy.next;
    }
};