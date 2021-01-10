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
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode *head_k = head, *tail_k = head;
    for (int i = 1; i < k; ++i) {
      head_k = head_k->next;
    }
    for (ListNode* tmp = head_k->next; tmp != nullptr; tmp = tmp->next) {
      tail_k = tail_k->next;
    }

    int tmp = head_k->val;
    head_k->val = tail_k->val;
    tail_k->val = tmp;
    return head;
  }
};