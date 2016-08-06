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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        while (hasKNodes(head, k)) {
            for (int i = 0; i < k; ++i) {
                ListNode *temp = head->next;
                head->next = curr->next;
                curr->next = head;
                head = temp;
            }
            for (int i = 0; i < k; ++i)
                curr = curr->next;
        }
        curr->next = head;
        return dummy.next;
    }
private:
    bool hasKNodes(ListNode *head, int k) {
        for (int i = 0; i < k; ++i) {
            if (!head)
                return false;
            head = head->next;
        }
        return true;
    }
};