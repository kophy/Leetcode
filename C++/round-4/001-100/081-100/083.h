class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0), *curr = &dummy, *last = nullptr;
        while (head) {
            auto tail = head->next;
            head->next = nullptr;
            if (!last || last->val!= head->val) {
                curr->next = head;
                curr = curr->next;
                last = head;
            }
            head = tail;
        }
        return dummy.next;
    }
};