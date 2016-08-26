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
        /*  to make a min heap */
        auto cmp = [] (ListNode *a, ListNode *b) -> bool {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> data(cmp);
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i])
                data.push(lists[i]);

        ListNode dummy(0), *curr = &dummy;
        while (!data.empty()) {
            ListNode *temp = data.top();
            data.pop();
            if (temp->next)
                data.push(temp->next);
            curr->next = temp;
            curr = curr->next;
        }
        return dummy.next;
    }
};