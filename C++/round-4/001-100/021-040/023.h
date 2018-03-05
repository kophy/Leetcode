class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode *a, ListNode *b) -> bool {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> data(cmp);
        for (ListNode *list : lists)
            if (list != nullptr)
                data.push(list);
        
        ListNode dummy(0), *curr = &dummy;
        while (!data.empty()) {
            ListNode *node = data.top();
            data.pop();
            if (node->next != nullptr)
                data.push(node->next);
            curr->next = node;
            curr = curr->next;
        }
        return dummy.next;
    }
};