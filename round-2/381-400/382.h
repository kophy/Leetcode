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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        _head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *result = NULL;
        ListNode *curr = _head;
        for (int i = 1; curr; ++i) {
            /*  joint probability
                the chance of result being replaced is 1/i
            */
            if(rand() % i == 0)
                result = curr;
            curr = curr->next;
        }
        return result? result->val : 0;
    }

private:
    ListNode *_head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */