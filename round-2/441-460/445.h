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
        stack<int> stk1, stk2;
        while (l1) {
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stk2.push(l2->val);
            l2 = l2->next;
        }
        ListNode dummy(0), *curr = &dummy;
        int carry = 0;
        while (!stk1.empty() || !stk2.empty() || carry) {
            int n1 = 0, n2 = 0;
            if (!stk1.empty()) {
                n1 = stk1.top();
                stk1.pop();
            }
            if (!stk2.empty()) {
                n2 = stk2.top();
                stk2.pop();
            }
            int sum = n1 + n2 + carry;
            ListNode *temp = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = dummy.next;
            dummy.next = temp;
        }
        return dummy.next;
    }
};