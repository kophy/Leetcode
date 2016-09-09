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
    ListNode *sortList(ListNode* head) {
        return mergeSort(head);
    }

private:
    ListNode *mergeSort(ListNode *begin) {
        if (begin == NULL || begin->next == NULL)
            return begin;

        /*  search the median element of a linked list
        	initialize fast with begin->next to avoid infinite loop
        */
        ListNode *slow = begin, *fast = begin->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *head1 = begin;
        ListNode *head2 = slow->next;
        slow->next = NULL;

        return merge(mergeSort(head1), mergeSort(head2));
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *curr = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1? l1 : l2;
        return dummy.next;
    }
};