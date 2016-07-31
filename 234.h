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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode rev(0);
        ListNode *prev = &rev;
        while (slow) {
            ListNode *temp = slow->next;
            slow->next = prev->next;
            prev->next = slow;
            slow = temp;
        }
        prev = rev.next;
        while (prev && head) {
            if (prev->val != head->val)
                return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};