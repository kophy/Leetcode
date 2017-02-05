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
        int m = length(headA), n = length(headB);
        if (m < n)
            swap(headA, headB);
        for (int i = 0; i < abs(m - n); ++i)
            headA = headA->next;
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }

private:
    int length(ListNode *head) {
        int length = 0;
        while (head) {
            ++length;
            head = head->next;
        }
        return length;
    }
};