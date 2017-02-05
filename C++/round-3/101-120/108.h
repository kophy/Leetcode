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
        return convertRange(nums, 0, (int)nums.size() - 1);
    }
    
private:
    TreeNode *convertRange(vector<int> &nums, int b, int e) {
        if (b > e)
            return nullptr;
        int m = b + (e - b) / 2;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = convertRange(nums, b, m - 1);
        root->right = convertRange(nums, m + 1, e);
        return root;
    }
};