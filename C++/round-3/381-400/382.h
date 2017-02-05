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
    Solution(ListNode *head) {
        data = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode result(0);
        int count = 0;
        for (auto curr = data; curr; curr = curr->next) {
            ++count;
            if (rand() % count == 0)
                result.val = curr->val;
        }
        return result.val;
    }

private:
    ListNode *data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */