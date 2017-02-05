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
        ListNode *curr = head;
        while (curr && curr->val == val) {
            head = curr->next;
            delete curr;
            curr = head;
        }
        
        while (curr && curr->next) {
            if (curr->next->val == val) {
                ListNode *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};