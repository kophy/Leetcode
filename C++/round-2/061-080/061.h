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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        /* k may be larger than list length */
        int len = length();
        k %= len;

        /* find head of last k nodes */
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < k; ++i)
            fast = fast->next;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }

private:
    int length(ListNode *head) {
        int length = 0;
        for (; head; head = head->next)
            ++length;
        return length;
    }
};