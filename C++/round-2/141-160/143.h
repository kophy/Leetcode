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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        /* find middle of the list */
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode dummy(0), *curr = slow->next;
        slow->next = NULL;

        /* reverse the rear half */
        while (curr) {
            ListNode *tail = curr->next;
            curr->next = dummy.next;
            dummy.next = curr;
            curr = tail;
        }
        ListNode result(0), *head1 = head, *head2 = dummy.next;
        curr = &result;

        /* re-combine the list */
        while (head1 && head2) {
            curr->next = head1;
            head1 = head1->next, curr = curr->next;
            curr->next = head2;
            head2 = head2->next, curr = curr->next;
        }
        curr->next = head1;
        head = dummy.next;
    }
};