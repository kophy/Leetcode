class Solution {
public:
	/** @param head The linked list's head.
	    Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode *head) {
		head_ = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		int result = 0;
		int count = 0;
		for (auto temp = head_; temp != nullptr; temp = temp->next) {
			++count;
			if (rand() % count == 0)
				result = temp->val;
		}
		return result;
	}

private:
	ListNode *head_;
};