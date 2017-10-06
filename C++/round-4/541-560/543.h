class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int result = 0;
        helper(result, root);
        return result;
    }
    
private:
    int helper(int &result, TreeNode *root) {
        if (!root)
            return 0;
        int left = helper(result, root->left);
        int right = helper(result, root->right);
        result = max(result, left + right);
        return 1 + max(left, right);
    }
};