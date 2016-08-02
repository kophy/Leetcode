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
    TreeNode *sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return nullptr;
        return sortedArrayToBST_help(nums, 0, nums.size() - 1);
    }
private:
    TreeNode *sortedArrayToBST_help(vector<int>& nums, int start, int end) {
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        if (start < mid)
            root->left = sortedArrayToBST_help(nums, start, mid - 1);
        if (end > start)
            root->right = sortedArrayToBST_help(nums, mid + 1, end);
        return root;
    }
};