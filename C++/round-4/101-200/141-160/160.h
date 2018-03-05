class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode *> stkA, stkB;
        for (; headA != nullptr; headA = headA->next)
            stkA.push(headA);
        for (; headB != nullptr; headB = headB->next)
            stkB.push(headB);
        ListNode *result = nullptr;
        while (!stkA.empty() && !stkB.empty() && stkA.top() == stkB.top()) {
            result = stkA.top();
            stkA.pop();
            stkB.pop();
        }
        return result;
    }
};