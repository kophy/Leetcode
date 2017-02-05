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
        stack<ListNode *> node_A, node_B;
        ListNode *result = NULL;
        for (; headA; headA = headA->next)
            node_A.push(headA);
        for (; headB; headB = headB->next)
            node_B.push(headB);
        while (!node_A.empty() && !node_B.empty() && node_A.top() == node_B.top()) {
            result = node_A.top();
            node_A.pop();
            node_B.pop();
        }
        return result;
    }
};