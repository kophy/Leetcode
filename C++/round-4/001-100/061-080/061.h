class Solution {
public:
    ListNode* rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        k %= getLength(head);
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < k; ++i)
            fast = fast->next;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
		slow->next = nullptr;
		return head;
    }
    
private:
    int getLength(ListNode *head) {
        int length = 0;
        for (; head != nullptr; head = head->next)
            ++length;
        return length;
    }
};