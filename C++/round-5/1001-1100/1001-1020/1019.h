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
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> result;
    for (; head != nullptr; head = head->next) {
      result.push_back(head->val);
    }
    stack<int> s;
    for (int i = (int)result.size() - 1; i >= 0; --i) {
      int num = result[i];
      while (!s.empty() && s.top() <= num) {
        s.pop();
      }
      result[i] = s.empty() ? 0 : s.top();
      s.push(num);
    }
    return result;
  }
};
