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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> data(cmp);
        for (auto list : lists)
            if (list)
                data.push(list);
        ListNode dummy(0), *curr = &dummy;
        while (!data.empty()) {
            auto temp = data.top();
            data.pop();
            if (temp->next)
                data.push(temp->next);
            curr->next = temp;
            curr = curr->next;
        }
        return dummy.next;
    }
};