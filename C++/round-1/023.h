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
        ListNode *result = new ListNode(0);
        ListNode *curr = result;

        auto cmp = [](ListNode *a, ListNode *b)->bool {return a->val > b->val;};
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> data(cmp);

        for (int i = 0; i < lists.size(); ++i)
            if (lists[i])
                data.emplace(lists[i]);
        while (!data.empty()) {
            ListNode *temp = data.top();
            data.pop();
            if (temp->next)
                data.emplace(temp->next);
            curr->next = temp;
            curr = curr->next;
        }
        ListNode *temp = result;
        result = result->next;
        delete temp;
        return result;
    }
};