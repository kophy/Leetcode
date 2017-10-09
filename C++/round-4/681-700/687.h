class Solution {
public:
    int longestUnivaluePath(TreeNode *root) {
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
        
        int single_path = 1, pivot_path = 0;
        if (root->left && root->val == root->left->val) {
            pivot_path += left;
            single_path = max(single_path, 1 + left);
        }
        if (root->right && root->val == root->right->val) {
            pivot_path += right;
            single_path = max(single_path, 1 + right);
        }
        result = max(result, pivot_path);
        return single_path;
    }
};