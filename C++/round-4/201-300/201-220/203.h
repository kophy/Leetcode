class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0), *curr = &dummy;
        for (; head != nullptr; head = head->next) {
            if (head->val != val) {
                curr->next = head;
                curr = curr->next;
            }
        }
        curr->next = nullptr;
        return dummy.next;
    }
};