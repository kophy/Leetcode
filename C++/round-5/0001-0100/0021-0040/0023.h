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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto cmp = [](ListNode *a, ListNode *b) -> bool { return a->val > b->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> data(cmp);
    for (auto list : lists) {
      if (list != nullptr) {
        data.push(list);
      }
    }
    ListNode dummy(0), *curr = &dummy;
    while (!data.empty()) {
      auto node = data.top();
      data.pop();
      if (node->next != nullptr) {
        data.push(node->next);
        node->next = nullptr;
      }
      curr->next = node;
      curr = curr->next;
    }
    return dummy.next;
  }
};
