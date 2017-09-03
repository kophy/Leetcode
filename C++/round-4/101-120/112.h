class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr)
            return sum == 0;
        else
            return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};