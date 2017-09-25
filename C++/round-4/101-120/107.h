class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        dfs(result, root, 0);
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    void dfs(vector<vector<int>> &result, TreeNode *root, int level) {
        if (!root)
            return;
        if (result.size() == level)
            result.push_back(vector<int>());
        result[level].push_back(root->val);
        dfs(result, root->left, level + 1);
        dfs(result, root->right, level + 1);
    }
};