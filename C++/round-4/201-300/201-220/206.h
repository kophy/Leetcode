class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        while (head != nullptr) {
            ListNode *rest = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = rest;
        }
        return dummy.next;
    }
};