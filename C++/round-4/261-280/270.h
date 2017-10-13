class Solution {
public:
    int closestValue(TreeNode *root, double target) {
        if (root->val > target && root->left) {
            int temp = closestValue(root->left, target);
            return abs(root->val - target) < abs(temp - target)? root->val : temp;
        }
        if (root->val < target && root->right) {
            int temp = closestValue(root->right, target);
            return abs(root->val - target) < abs(temp - target)? root->val : temp;
        }
        return root->val;
    }
};