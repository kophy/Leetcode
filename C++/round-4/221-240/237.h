class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode *pivot = node->next;
		node->val = pivot->val;
		node->next = pivot->next;
		delete pivot;
	}
};