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
    bool isPalindrome(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *temp = findPrevMiddle(head);
        ListNode *curr = reverse(temp->next);
        temp->next = NULL;
        while (head && curr) {
            if (head->val != curr->val)
                return false;
            head = head->next;
            curr = curr->next;
        }
        return true;
    }

private:
    ListNode *findPrevMiddle(ListNode *head) {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

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