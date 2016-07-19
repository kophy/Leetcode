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
        if (!head || !head->next)
            return head;
        ListNode *curr = head;
        while (curr->next) {
            if (curr->val == curr->next->val) {
                ListNode *temp = curr->next;
                curr->next = temp->next;
                delete temp;
            } else
                curr = curr->next;
        }
        return head;
    }
};