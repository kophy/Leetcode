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
  ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0), *curr = &dummy;
    while (head != nullptr && head->next != nullptr) {
      ListNode *a = head, *b = head->next;
      head = head->next->next;
      curr->next = b;
      curr = curr->next;
      curr->next = a;
      curr = curr->next;
      curr->next = nullptr;
    }
    curr->next = head;
    return dummy.next;
  }
};
