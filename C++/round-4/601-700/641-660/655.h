class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int row = getMaxDepth(root);
        int col = (1 << row) - 1;
        vector<vector<string>> result(row, vector<string>(col, ""));
        helper(result, root, 0, 0, col - 1);
        return result;
    }
    
private:
    int getMaxDepth(TreeNode *root) {
        return root? max(getMaxDepth(root->left), getMaxDepth(root->right)) + 1 : 0;
    }
    
    // recursion with updated range
    void helper(vector<vector<string>> &result, TreeNode *root, int row, int col_begin, int col_end) {
        if (!root || row == result.size())
            return;
        int col_mid = (col_begin + col_end) / 2;
        result[row][col_mid] = to_string(root->val);
        helper(result, root->left, row + 1, col_begin, col_mid - 1);
        helper(result, root->right, row + 1, col_mid + 1, col_end);
    }
};