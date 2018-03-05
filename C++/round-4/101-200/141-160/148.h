class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head1 = head, *head2 = slow->next;
        slow->next = nullptr;
        head1 = sortList(head1);
        head2 = sortList(head2);
        return merge(head1, head2);
    }
    
private:
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode dummy(0), *curr = &dummy;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
        curr->next = head1? head1 : head2;
        return dummy.next;
    }
}; 