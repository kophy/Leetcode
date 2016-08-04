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
    void reorderList(ListNode *head) {
        if (len(head) <= 2)
            return;

        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode dummy(0);
        ListNode *curr = slow->next;
        slow->next = nullptr;
        while (curr) {
            ListNode *temp = curr->next;
            curr->next = dummy.next;
            dummy.next = curr;
            curr = temp;
        }

        ListNode result(0);
        curr = &result;
        ListNode *head1 = head, *head2 = dummy.next;
        while (head1 && head2) {
            curr->next = head1;
            head1 = head1->next;
            curr = curr->next;
            curr->next = head2;
            head2 = head2->next;
            curr = curr->next;
        }
        if (head1)
            curr->next = head1;
        head = result.next;
    }

private:
    int len(ListNode *head) {
        int len = 0;
        while (head) {
            head = head->next;
            ++len;
        }
        return len;
    }
};