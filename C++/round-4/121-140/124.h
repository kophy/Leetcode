class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int result = INT_MIN;
        helper(result, root);
        return result;
    }
    
private:
    int helper(int &result, TreeNode *root) {
        if (!root)
            return 0;
        int left = helper(result, root->left), right = helper(result, root->right);
        
        // four possible paths across current node 
        int pivot = max(left, 0) + root->val + max(right, 0);
        result = max(result, pivot);
        
        return max(max(left, right), 0) + root->val;
    }
};