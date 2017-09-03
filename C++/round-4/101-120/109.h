class Solution {
public:
    TreeNode *sortedListToBST(ListNode* head) {
        return sortedListToBST(head, nullptr);
    }
    
private:
    TreeNode *sortedListToBST(ListNode *begin, ListNode *end) {
        if (begin == end)
            return nullptr;
        ListNode *slow = begin, *fast = begin;
        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(begin, slow);
        root->right = sortedListToBST(slow->next, end);
        return root;
    }
};