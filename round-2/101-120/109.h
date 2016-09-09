/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode* head) {
        return generate(head, NULL);
    }

private:
    /* 	begin is included in the generating range, but end is not
    	so that's like [begin, end)
    	when begin == end, there is no element in the range
    */
    TreeNode *generate(ListNode *begin, ListNode *end) {
        if (begin == end)
            return NULL;

        ListNode *slow = begin, *fast = begin;

        // find median of a linked list -- the tree is roughly balanced, not perfectly.
        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = generate(begin, slow);
        root->right = generate(slow->next, end);
        return root;
    }
};