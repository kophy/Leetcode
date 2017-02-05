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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = new ListNode(0);
        ListNode* curr = result;

        while (l1 && l2) {
            int num1 = l1->val;
            l1 = l1->next;
            int num2 = l2->val;
            l2 = l2->next;
            curr->next = new ListNode((num1 + num2 + carry) % 10);
            curr = curr->next;
            carry = (num1 + num2 + carry) / 10;
        }

        while (l1) {
            int num1 = l1->val;
            l1 = l1->next;
            curr->next = new ListNode((num1 + carry) % 10);
            curr = curr->next;
            carry = (num1 + carry) / 10;
        }

        while (l2) {
            int num2 = l2->val;
            l2 = l2->next;
            curr->next = new ListNode((num2 + carry) % 10);
            curr = curr->next;
            carry = (num2 + carry) / 10;
        }

        if (carry)
            curr->next = new ListNode(carry);

        return result->next;
    }
};