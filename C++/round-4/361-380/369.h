class Solution {
public:
    ListNode *plusOne(ListNode *head) {
        head = reverse(head);
        ListNode dummy(0), *curr = &dummy;
        int carry = 1;
        while (head || carry) {
            int sum = carry;
            if (head) {
                sum += head->val;
                head = head->next;
            }
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            carry = sum / 10;
        }
        return reverse(dummy.next);
    }
    
private:
    ListNode *reverse(ListNode *head) {
        ListNode dummy(0);
        while (head) {
            ListNode *tail = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tail;
        }
        return dummy.next;
    }
};