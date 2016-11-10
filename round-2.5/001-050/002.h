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
        ListNode dummy(0), *curr = &dummy;
        int n1, n2, carry = 0;
        while (l1 || l2 || carry) {
            n1 = l1? l1->val : 0;
            if (l1) l1 = l1->next;
            n2 = l2? l2->val : 0;
            if (l2) l2 = l2->next;
            int sum = (n1 + n2 + carry);
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            carry = sum / 10;
        }
        return dummy.next;
    }
};