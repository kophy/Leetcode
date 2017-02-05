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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return generate(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *generate(vector<int> &nums, int begin, int end) {
        if (begin > end)
            return NULL;
        int mid = (begin + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = generate(nums, begin, mid - 1);
        root->right = generate(nums, mid + 1, end);
    }
};