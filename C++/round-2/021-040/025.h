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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0), *curr = &dummy;
        while (hasKNodes(head, k)) {
            for (int i = 0; i < k; ++i) {
                ListNode *tail = head->next;
                head->next = curr->next;
                curr->next = head;
                head = tail;
            }
            for (int i = 0; i < k; ++i)
                curr = curr->next;
            curr->next = NULL;
        }
        curr->next = head;
        return dummy.next;
    }

private:
    bool hasKNodes(ListNode *head, int k) {
        for (int i = 0; i < k; ++i) {
            if (head == NULL)
                return false;
            head = head->next;
        }
        return true;
    }
};