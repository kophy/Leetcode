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
    ListNode* sortList(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode *slow = head, *fast = head->next;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* head1 = head;
		ListNode *head2 = slow->next;
		slow->next = NULL;
		head = merge(sortList(head1), sortList(head2));
		return head;
    }
	
	ListNode *merge(ListNode *l1, ListNode* l2) {
		ListNode dummy(0);
		ListNode *curr = &dummy;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				curr->next = l1;
				l1 = l1->next;
				curr = curr->next;
			}
			else {
				curr->next = l2;
				l2 = l2->next;
				curr = curr->next;
			}
		}
		if (l1)
			curr->next = l1;
		if (l2)
			curr->next = l2;
		return dummy.next;
	}
};