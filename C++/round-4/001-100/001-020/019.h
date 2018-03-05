class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *slow = &dummy, *fast = &dummy;
        for (int i = 0; i < n; ++i)
            fast = fast->next;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *pivot = slow->next;
        slow->next = slow->next->next;
        delete pivot;
        return dummy.next;
    }
};