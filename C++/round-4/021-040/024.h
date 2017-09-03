class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0), *curr = &dummy;
        while (head != nullptr) {
            if (hasKListNodes(head, 2)) {
                for (int i = 0; i < 2; ++i) {
                    ListNode *rest = head->next;
                    head->next = curr->next;
                    curr->next = head;
                    head = rest;
                }
                for (int i = 0; i < 2; ++i)
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