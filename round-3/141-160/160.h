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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode *> stkA, stkB;
        while (headA) {
            stkA.push(headA);
            headA = headA->next;
        }
        while (headB) {
            stkB.push(headB);
            headB = headB->next;
        }
        ListNode *result = NULL;
        while (!stkA.empty() && !stkB.empty() && stkA.top() == stkB.top()) {
            result = stkA.top();
            stkA.pop();
            stkB.pop();
        }
        return result;
    }
};