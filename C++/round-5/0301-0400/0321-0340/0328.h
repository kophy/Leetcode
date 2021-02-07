/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    ListNode dummy_odd, dummy_even;
    ListNode *odd = &dummy_odd, *even = &dummy_even;

    int i = 1;
    while (head != nullptr) {
      if (i % 2 == 1) {
        odd->next = head;
        odd = odd->next;
      } else {
        even->next = head;
        even = even->next;
      }
      ++i;
      head = head->next;
    }
    odd->next = dummy_even.next;
    even->next = nullptr;
    return dummy_odd.next;
  }
};