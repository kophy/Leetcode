class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode *root) {
        vector<vector<int>> result;
        helper(result, root);
        return result;
    }
    
private:
    int helper(vector<vector<int>> &result, TreeNode *root) {
        if (!root)
            return 0;
        int left = helper(result, root->left);
        int right = helper(result, root->right);
        int depth = max(left, right) + 1;
        if (result.size() < depth)
            result.resize(depth);
        result[depth - 1].push_back(root->val);
        return depth;
    }
};