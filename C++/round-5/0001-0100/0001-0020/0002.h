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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy(0), *curr = &dummy;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      int n1 = 0, n2 = 0;
      if (l1 != nullptr) {
        n1 = l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        n2 = l2->val;
        l2 = l2->next;
      }
      int sum = n1 + n2 + carry;
      curr->next = new ListNode(sum % 10);
      curr = curr->next;
      carry = sum / 10;
    }
    return dummy.next;
  }
};
