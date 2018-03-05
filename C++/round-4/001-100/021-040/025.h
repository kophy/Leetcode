class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0), *curr = &dummy;
        while (head != nullptr) {
            if (hasKListNodes(head, k)) {
                for (int i = 0; i < k; ++i) {
                    ListNode *rest = head->next;
                    head->next = curr->next;
                    curr->next = head;
                    head = rest;
                }
                for (int i = 0; i < k; ++i)
                    curr = curr->next;
            } else {
                curr->next = head;
                head = nullptr;
            }
        }
        return dummy.next;
    }
    
private:
    bool hasKListNodes(ListNode* head, int k) {
        for (int i = 0; i < k; ++i) {
            if (head == nullptr)
                return false;
            head = head->next;
        }
        return true;
    }
};